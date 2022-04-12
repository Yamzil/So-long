/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:38:34 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/12 01:24:16 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_g	map;
	t_g	player;
	t_g	exit;
	t_g	collectibles;

	player.player = 0;
	exit.exit = 0;
	collectibles.collectibles = 0;
	if (ft_checkarg(ac, av))
		return (0);
	ft_getmap(&map, av);
	ft_checklen(&map);
	ft_checkelemnts(&map);
	ft_contents(map);
	ft_getlencolumns(av, &map);
	ft_getlenrow(&map);
	ft_solong(&map);
}
