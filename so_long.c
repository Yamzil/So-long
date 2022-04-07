/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:38:34 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/07 02:34:46 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_g	map;
	t_g	player;
	t_g	exit;
	t_g	collectibles;

	map.map = av;
	player.player = 0;
	exit.exit = 0;
	collectibles.collectibles = 0;
	map = ft_getmap(map, av);
	ft_checkelemnts(map, player, exit, collectibles);
	if (ft_checkarg(ac, av))
		return (0);
	ft_checklen(av, map);
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, WIN_HEIGHT, WIN_WIDTH, "So Long");
	// mlx_loop(mlx);
}