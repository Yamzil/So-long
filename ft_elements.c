/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:48:16 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/11 02:01:55 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkplayer(t_g *map)
{
	int	i;
	int	j;

	i = 0;
	map->player = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				map->player++;
			j++;
		}
		i++;
	}
	if (map->player != 1)
	{
		write(2, "Check Player !\n", 16);
		exit (1);
	}
}

void	ft_checkexit(t_g *map)
{
	int	i;
	int	j;

	i = 0;
	map->exit = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'E')
				map->exit++;
			j++;
		}
		i++;
	}
	if (map->exit < 1)
	{
		write(2, "Check exit !\n", 14);
		exit (1);
	}
}

void	ft_checkcollectibles(t_g *map)
{
	int	i;
	int	j;

	i = 0;
	map->collectibles = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->collectibles++;
			j++;
		}
		i++;
	}
	if (map->collectibles < 1)
	{
		write(2, "Check collectibles !\n", 22);
		exit (1);
	}
}

void	ft_contents(t_g map)
{
	ft_checkplayer(&map);
	ft_checkexit(&map);
	ft_checkcollectibles(&map);
}

void	ft_checkelemnts(t_g *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '\n'
				&& map->map[i][j] != '0' && map->map[i][j] != 'E'
				&& map->map[i][j] != 'C' && map->map[i][j] != 'P'
				&& map->map[i][j] != '\0')
			{
				write(2, "Elements Error\n", 16);
				exit (0);
			}
			j++;
		}
		i++;
	}
}
