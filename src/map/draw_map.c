/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:39:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 16:14:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

void	draw_map(t_game g)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	while (g.map.map[y])
	{
		x = 0;
		while (x < g.map.size.x)
		{
			mlx_put_image_to_window(g.mlx, g.win, g.assets.block[0].img, \
									UNIT_X * x, UNIT_Y * y);
			i = 0;
			if (g.map.map[y][x] == '1')
				i = 3;
			mlx_put_image_to_window(g.mlx, g.win, g.assets.block[i].img, \
									UNIT_X * x, UNIT_Y * y);
			x++;
		}
		y++;
	}
}
