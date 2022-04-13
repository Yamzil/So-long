/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:57:14 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/13 00:35:06 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_getlencolumns(char **av, t_g *map)
{
	char	*line;
	int		count;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		count++;
		line = get_next_line(fd);
	}
	map->height = count;
}

void	ft_getlenrow(t_g *map)
{
	int	j;

	j = 0;
	while (map->map[0][j] != '\n')
		j++;
	map->width = j;
}

int	ft_getlast(t_g *map)
{
	int	i;

	i = 0;
	while (map->map[map->height][i] != '\0')
		i++;
	return (i);
}
