/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:57:14 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/07 01:57:10 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_getlencolumns(char **av)
{
	int		count;
	int		fd;
	char	*map;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	map = get_next_line(fd);
	count = 0;
	while (map)
	{
		count++;
		map = get_next_line(fd);
	}
	return (count);
}

int	ft_getlenrow(t_g map)
{
	int	j;

	j = 0;
	while (map.map[0][j] != '\n')
		j++;
	return (j);
}