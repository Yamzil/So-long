/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:31:40 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/07 02:29:03 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkarg(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	k = ft_strlen(av[1]);
	i = k - 4;
	j = k - i;
	if (ac != 2)
	{
		write(2, "Invalid Arguments Numbers\n", 27);
		return (1);
	}
	else if (ac == 2)
	{
		if (!ft_strnstr(av[1], ".ber"))
			write (2, "Invalid Extention Type\n", 24);
	}
	return (1);
}

t_g	ft_getmap(t_g map, char **av)
{
	int	len;
	int	fd;
	int	i;

	len = ft_getlencolumns(av);
	fd = open(av[1], O_RDONLY);
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

void	ft_checklen(char **av, t_g map)
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