/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:36:13 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/19 20:43:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_map_data(t_game *g)
{
	int	x;
	int	y;

	y = 1;
	while (y < g->map.size.y - 1)
	{
		x = 1;
		while (x < g->map.size.x - 1)
		{
			if (g->map.data[y][x].hit)
			{
				if (g->frame - g->map.data[y][x].frame_hit == 1)
					g->map.data[y][x].offset = init_point(0, -2);
				else if (g->frame - g->map.data[y][x].frame_hit == 2)
					g->map.data[y][x].offset = init_point(0, -4);
				else if (g->frame - g->map.data[y][x].frame_hit == 3)
					g->map.data[y][x].offset = init_point(0, -6);
				else if (g->frame - g->map.data[y][x].frame_hit == 4)
					g->map.data[y][x].offset = init_point(0, -8);
				else if (g->frame - g->map.data[y][x].frame_hit == 5)
					g->map.data[y][x].offset = init_point(0, -6);
				else if (g->frame - g->map.data[y][x].frame_hit == 6)
					g->map.data[y][x].offset = init_point(0, -4);
				else if (g->frame - g->map.data[y][x].frame_hit == 7)
					g->map.data[y][x].offset = init_point(0, -2);
				else if (g->frame - g->map.data[y][x].frame_hit == 8)
				{
					g->map.data[y][x].hit = ft_false;
					g->map.data[y][x].offset = init_point(0, 0);
				}
			}
			x++;
		}
		y++;
	}
}
