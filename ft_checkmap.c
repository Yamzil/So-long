/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:31:40 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/08 01:58:06 by yamzil           ###   ########.fr       */
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

t_g	ft_getmap(t_g map, char **av)
{
	int	len;
	int	fd;
	int	i;

	len = ft_getlencolumns(av);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit (0);
	map.map = (char **)malloc(sizeof(char **) * (len + 1));
	if (!map.map)
		exit (1);
	i = 0;
	while (1)
	{
		map.map[i] = get_next_line(fd);
		if (map.map[i] == '\0')
			break ;
		i++;
	}
	map.map[i] = NULL;
	return (map);
}

void	ft_checksurrounded(char **av, t_g map)
{
	int	len;
	int	row;
	int	i;
	int	j;

	len = ft_getlencolumns(av);
	row = ft_getlenrow(map);
	map = ft_getmap(map, av);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < row)
		{
			if (map.map[0][j] != '1' || map.map[len - 1][j] != '1'
			|| map.map[i][0] != '1' || map.map[i][row - 1] != '1')
			{
				write(2, "Map is not surrounded with [1]\n", 32);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_checklen(t_g map)
{
	size_t	row;
	int		i;

	row = ft_getlenrow(map);
	i = 0;
	while (map.map[i])
	{
		if (row != ft_strlen(map.map[i]))
		{
			write(1, "Length's Error\n", 16);
			exit (0);
		}
		i++;
	}
}