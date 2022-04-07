/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:48:16 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/07 02:32:15 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkplayer(t_g map, t_g player)
{
	int	i;
	int	j;

	i = 0;
	player.player = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == 'P')
				player.player++;
			j++;
		}
		i++;
	}
	if (player.player > 1)
	{
		write(2, "Map has more than 1 player !", 29);
		return (0);
	}
	printf("|%d|\n", player.player);
	return (player.player);
}

int	ft_checkexit(t_g map, t_g exit)
{
	int	i;
	int	j;

	i = 0;
	exit.exit = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == 'E')
				exit.exit++;
			j++;
		}
		i++;
	}
	printf("[%d]\n", exit.exit);
	return (exit.exit);
}

int	ft_checkcollectibles(t_g map, t_g collectibles)
{
	int	i;
	int	j;

	i = 0;
	collectibles.collectibles = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == 'E')
				collectibles.collectibles++;
			j++;
		}
		i++;
	}
	printf("{%d}\n", collectibles.collectibles);
	return (collectibles.collectibles);
}

void	ft_contents(t_g map, t_g player, t_g exit, t_g collectibles)
{
	ft_checkplayer(map, player);
	ft_checkexit(map, exit);
	ft_checkcollectibles(map, collectibles);
}

int	ft_checkelemnts(t_g map, t_g player, t_g exit, t_g collectibles)
{
	int	i;
	int	j;

	i = 0;
	while (map.map[i])
	{
		puts("ss");
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] != 'P' || map.map[i][j] != 'C' || map.map[i][j] != 'E')
			{
				write(2, "Error\n : Une menace a ete detectee !\n", 38);
				return (0);
			}
			else
			{
				ft_contents(map, player, exit, collectibles);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (1);
}
