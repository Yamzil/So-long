/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norminette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:30:22 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/13 18:05:44 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy(void)
{
	exit(1);
	return (0);
}

void	ft_initial(t_g *map, int i, int j)
{
	map->j_place = j;
	map->i_place = i;
}
