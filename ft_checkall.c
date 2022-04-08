/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamzil <yamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:19:16 by yamzil            #+#    #+#             */
/*   Updated: 2022/04/08 02:20:48 by yamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_checkall(char **av, t_g map, t_g player, t_g exit, t_g collectibles)
{
    ft_checkelemnts(av, map);
	ft_checksurrounded(av, map);
	ft_contents(map, player, exit, collectibles);
	ft_checkelemnts(av, map);
}