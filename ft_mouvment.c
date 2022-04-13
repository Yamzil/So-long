/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouvment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:00:34 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/13 18:05:33 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mouvment(int key_code, t_g *map, int i, int j)
{
	i = map->i_place;
	j = map->j_place;
	if (key_code == key_w && map->map[i - 1][j] != '1')
	{
		ft_keyforward(map, i, j);
		ft_check(key_w, map, i - 1, j);
	}
	else if (key_code == key_s && map->map[i + 1][j] != '1')
	{
		ft_keydown(map, i, j);
		ft_check(key_s, map, i + 1, j);
	}
	else if (key_code == key_cross || key_code == key_ecs)
		ft_destroy();
	map->counter++;
	printf("Number of Mouvment : %d\n", map->counter);
	return (0);
}

int	ft_mouvmenttwo(int key_code, t_g *map, int i, int j)
{
	i = map->i_place;
	j = map->j_place;
	if (key_code == key_a && map->map[i][j - 1] != '1')
	{
		ft_checkleft(map, i, j);
		ft_check(key_a, map, i, j - 1);
	}
	else if (key_code == key_d && map->map[i][j + 1] != '1')
	{
		ft_checkright(map, i, j);
		ft_check(key_d, map, i, j + 1);
	}
	else if (key_code == key_cross || key_code == key_ecs)
		ft_destroy();
	map->counter++;
	printf("Number of Mouvment : %d\n", map->counter);
	return (0);
}

int	ft_donemvm(int key_code, t_g *map, int i, int j)
{
	ft_mouvment(key_code, map, i, j);
	ft_mouvmenttwo(key_code, map, i, j);
	return (0);
}

void	ft_check(int key_code, t_g *map, int i, int j)
{
	if (key_code == key_w && (map->map[i][j] == 'C' || map->map[i][j] == 'E'))
		ft_winner(map, i, j);
	else if (key_code == key_s && (map->map[i][j] == 'C'
		|| map->map[i][j] == 'E'))
		ft_winner(map, i, j);
	else if (key_code == key_d && (map->map[i][j] == 'C'
		|| map->map[i][j] == 'E'))
		ft_winner(map, i, j);
	else if (key_code == key_a && (map->map[i][j] == 'C'
		|| map->map[i][j] == 'E'))
		ft_winner(map, i, j);
}

void	ft_winner(t_g *map, int i, int j)
{
	if (map->map[i][j] == 'C')
	{
		map->collectibles--;
		map->map[i][j] = '0';
	}
	else
	{
		if (map->collectibles == 0)
		{
			write(1, "You Win !\n", 11);
			exit(0);
		}
	}
}
