/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouvment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:00:34 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/12 02:54:20 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mouvment(int key_code, t_g *map)
{
	int	i;
	int	j;

	i = map->i_place;
	j = map->j_place;	
	if (key_code == key_w && map->map[i - 1][j] != '1')
	{
    	mlx_put_image_to_window(map->mlx, map->mlx_win, map->hero, j * map->hero_width , (i - 1)* map->hero_height);
    	mlx_put_image_to_window(map->mlx, map->mlx_win, map->grasse, j * map->grasse_width , i * map->grasse_height);
		map->i_place = i - 1;
		map->j_place = j;
		ft_check(key_w, map, i - 1, j);
	}
	if (key_code == key_s && map->map[i + 1][j] != '1')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->hero, j * map->hero_width , (i + 1)* map->hero_height);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->grasse, j * map->grasse_width , i * map->grasse_height);
		map->i_place = i + 1;
		map->j_place = j;
		ft_check(key_s, map, i + 1, j);
	}
	if (key_code == key_a && map->map[i][j - 1] != '1')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->hero, (j - 1) * map->hero_width , i * map->hero_height);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->grasse, j * map->grasse_width , i * map->grasse_height);
		map->i_place = i;
		map->j_place = j - 1;
		ft_check(key_a, map, i, j - 1);
	}
	if (key_code == key_d && map->map[i][j + 1] != '1')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->hero, (j + 1) * map->hero_width , i * map->hero_height);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->grasse, j * map->grasse_width , i * map->grasse_height);
		map->i_place = i;
		map->j_place = j + 1; 
		ft_check(key_d, map, i, j + 1);
	}
	printf("%d\n", map->collectibles);
	return (0);
}

void	ft_check(int key_code, t_g *map, int i, int j)
{
	if (key_code == key_w && (map->map[i][j] == 'C' || map->map[i][j] == 'E'))
	{
		if (map->map[i][j] == 'C')
		{
			map->collectibles--;
			map->map[i][j] = '0';
		}
		else
		{
			if (map->collectibles == 0)
				exit(0);
		}
	}
	else if (key_code == key_s && (map->map[i][j] == 'C' || map->map[i][j] == 'E'))
	{
		if (map->map[i][j] == 'C')
		{
			map->collectibles--;
			map->map[i][j] = '0';
		}
		else
		{
			if (map->collectibles == 0)
				exit(0);
		}
	}
	else if (key_code == key_d && (map->map[i][j] == 'C' || map->map[i][j] == 'E'))
	{
		if (map->map[i][j] == 'C')
		{
			map->collectibles--;
			map->map[i][j] = '0';
		}
		else
		{
			if (map->collectibles == 0)
				exit(0);
		}
	}
	else if (key_code == key_a && (map->map[i][j] == 'C' || map->map[i][j] == 'E'))
	{
		if (map->map[i][j] == 'C')
		{
			map->collectibles--;
			map->map[i][j] = '0';
		}
		else
		{
			if (map->collectibles == 0)
				exit(0);
		}
	}
}