/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:48:16 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/08 01:53:56 by yamzil           ###   ########.fr       */
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
	if (player.player != 1)
	{
		write(2, "Check Player !\n", 16);
		return (0);
	}
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
	if (exit.exit != 1)
	{
		write(2, "Check exit !\n", 14);
		return (0);
	}
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
	if (collectibles.collectibles != 1)
	{
		write(2, "Check collectibles !\n", 22);
		return (0);
	}
	return (collectibles.collectibles);
}

void	ft_contents(t_g map, t_g player, t_g exit, t_g collectibles)
{
	ft_checkplayer(map, player);
	ft_checkexit(map, exit);
	ft_checkcollectibles(map, collectibles);
}

void	ft_checkelemnts(char **av, t_g map)
{
	int	columns;
	int	row;
	int	i;
	int	j;

	i = 0;
	columns = ft_getlencolumns(av);
	row = ft_getlenrow(map);
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] != '1' && map.map[i][j] != '\n'
				&& map.map[i][j] != '0' && map.map[i][j] != 'E'
				&& map.map[i][j] != 'C' && map.map[i][j] != 'P'
				&& map.map[i][j] != '\0')
			{
				write(2, "Elements Error\n", 16);
				exit (0);
			}
			j++;
		}
		i++;
	}
}
