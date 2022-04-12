/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:09:30 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/12 02:24:48 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putimg(t_g *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->wall, j * map->wall_width , i * map->wall_height);
			else if (map->map[i][j] == '0')
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->grasse, j * map->grasse_width , i * map->grasse_height);
			else if (map->map[i][j] == 'P')
			{
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->hero, j * map->hero_width , i * map->hero_height);
				map->j_place = j;
				map->i_place = i;
			}
			else if (map->map[i][j] == 'C')
			{
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->lettuce, j * map->lettuce_width , i * map->lettuce_height);
				map->collectibles++;
			}
			else if (map->map[i][j] == 'E')
			{
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->grasse, j * map->grasse_width , i * map->grasse_height);
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->door, j * map->door_width , i * map->door_height);
			}
			j++;
		}
		i++;
	}
}

void	ft_solong(t_g *map)
{

	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, (map->width) * 48, (map->height) * 48, "Coucou");
	map->wall = mlx_xpm_file_to_image(map->mlx, "img/Wood.xpm", &map->wall_height, &map->wall_width);
	map->grasse = mlx_xpm_file_to_image(map->mlx, "img/land.xpm", &map->grasse_height, &map->grasse_width);
	map->hero = mlx_xpm_file_to_image(map->mlx, "img/Hero.xpm", &map->hero_height, &map->hero_width);		
	map->lettuce = mlx_xpm_file_to_image(map->mlx, "img/Lettuce.xpm", &map->lettuce_height, &map->lettuce_width);		
	map->door = mlx_xpm_file_to_image(map->mlx, "img/door.xpm", &map->door_height, &map->door_width);		
	ft_putimg(map);
	mlx_hook(map->mlx_win, 2, 0, ft_mouvment, map);
	//printf("%d", map->collectibles);
	mlx_loop(map->mlx);
}
