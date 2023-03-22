/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:39:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 15:31:38 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

void	draw_map(t_game g)
{
	int		x;
	int		y;

	y = 0;
	while (y < g.map.size.y)
	{
		x = 0;
		while (x < g.map.size.x)
		{
			mlx_put_image_to_window(g.mlx, g.win, g.assets.block[3].img, \
									UNIT_X * x, UNIT_Y * y);
			if (g.map.map[y][x] < '3')
			{
				mlx_put_image_to_window(g.mlx, g.win, \
									g.assets.block[g.map.map[y][x] - '0'].img, \
									UNIT_X * x, \
									UNIT_Y * y + g.map.data[y][x].offset.y);
			}
			x++;
		}
		y++;
	}
}
