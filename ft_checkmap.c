/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:31:40 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/11 02:09:56 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkarg(int ac, char **av)
{
	int	k;

	k = ft_strlen(av[1]);
	if (ac != 2)
	{
		write(2, "Invalid Arguments Numbers\n", 27);
		return (1);
	}
	else if (ac == 2)
	{
		if (av[1][k - 1] != 'r' || av[1][k - 2] != 'e'
			|| av[1][k - 3] != 'b' || av[1][k - 4] != '.')
		{
			write (2, "Invalid Extention Type\n", 24);
			return (1);
		}
	}
	return (0);
}

void	ft_getmap(t_g *map, char **av)
{
	int	fd;
	int	i;
	
	ft_getlencolumns(av, map);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit (0);
	map->map = (char **)malloc(sizeof(char **) * (map->height + 1));
	if (!map->map)
		exit (1);
	i = 0;
	while (1)
	{
		map->map[i] = get_next_line(fd);
		if (map->map[i] == '\0')
			break ;
		i++;
	}
	map->map[i] = NULL;
}

// void	ft_checksurrounded(char **av, t_g *map)
// {
// 	int	i;
// 	int	j;

// 	// ft_getlencolumns(map, av);
// 	// ft_getlenrow(map);
// 	ft_getmap(map, av);
// 	i = 0;
// 	while (i < map->height)
// 	{
// 		j = 0;
// 		while (j < map->width)
// 		{
// 			if (map->map[0][j] != '1' || map->map[map->height][j] != '1'
// 			|| map->map[i][0] != '1' || map->map[i][map->width] != '1')
// 			{
// 				write(2, "Map is not surrounded with [1]\n", 32);
// 				exit(1);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	ft_checklen(t_g *map)
{
	int	first;
	int	last;
	int	i;

	// len = ft_getlencolumns(map, av);
	first = ft_strlen(map->map[0]);
	last = ft_strlen(map->map[map->height - 1]);
	if (last != ft_strlen(map->map[0]) - 1)
	{
		write(2, "Check length \n", 15);
		exit (1);
	}
	i = 1;
	while (map->map[i + 1])
	{
		if (ft_strlen(map->map[i]) != first)
		{
			write(2, "Check length \n", 15);
			exit (1);
		}
		i++;
	}
}
