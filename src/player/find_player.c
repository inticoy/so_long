/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:25:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/15 20:25:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

t_point	find_player(t_map map)
{
	t_point	pos_player;
	int		x;
	int		y;

	pos_player = init_point(0, 0);
	y = 0;
	while (y < map.size.y)
	{
		x = 0;
		while (x < map.size.x)
		{
			if (map.map[y][x] == 'P')
			{
				pos_player = init_point(x, y);
				return (pos_player);
			}
			x++;
		}
		y++;
	}
	return (pos_player);
}