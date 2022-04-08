/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:38:34 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/08 02:21:56 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_g		map;
	t_g		player;
	t_g		exit;
	t_g		collectibles;
	t_g 	img;

	map.map = av;
	player.player = 0;
	exit.exit = 0;
	collectibles.collectibles = 0;
	if (ft_checkarg(ac, av))
		return (0);
	map = ft_getmap(map, av);
	ft_checkelemnts(av, map);
	ft_checksurrounded(av, map);
	ft_contents(map, player, exit, collectibles);
	ft_checkelemnts(av, map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_HEIGHT, WIN_WIDTH, "So Long");
	img.img = mlx_new_image(mlx, WIN_HEIGHT, WIN_WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}