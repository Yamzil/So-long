/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:50:39 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/13 18:05:21 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_keyforward(t_g *map, int i, int j)
{
	if (map->map[i - 1][j] != 'E')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->hero, j * map->hero_width, (i - 1) * map->hero_height);
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->grasse, j * map->grasse_width, i * map->grasse_height);
		map->i_place = i - 1;
		map->j_place = j;
	}
}

void	ft_keydown(t_g *map, int i, int j)
{
	if (map->map[i + 1][j] != 'E')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->hero,
			j * map->hero_width, (i + 1) * map->hero_height);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->grasse,
			j * map->grasse_width, i * map->grasse_height);
		map->i_place = i + 1;
		map->j_place = j;
	}
}

void	ft_checkleft(t_g *map, int i, int j)
{
	if (map->map[i][j - 1] != 'E')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->hero,
			(j - 1) * map->hero_width, i * map->hero_height);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->grasse,
			j * map->grasse_width, i * map->grasse_height);
		map->i_place = i;
		map->j_place = j - 1;
	}
}

void	ft_checkright(t_g *map, int i, int j)
{
	if (map->map[i][j + 1] != 'E')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->hero,
			(j + 1) * map->hero_width, i * map->hero_height);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->grasse,
			j * map->grasse_width, i * map->grasse_height);
		map->i_place = i;
		map->j_place = j + 1;
	}
}
