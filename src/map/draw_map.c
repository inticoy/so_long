/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:39:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/08 16:17:11 by gyoon            ###   ########.fr       */
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
	void	*img;


	y = 0;
	while (g.map.map[y])
	{
		x = 0;
		while (x < g.map.size.x)
		{
			img = g.assets.block[0].img;
			mlx_put_image_to_window(g.mlx, g.win, img, PIXEL_X * x, PIXEL_Y * y);
			i = 0;
			if (g.map.map[y][x] == '1')
				i = 3;
			img = g.assets.block[i].img;
			mlx_put_image_to_window(g.mlx, g.win, img, PIXEL_X * x, PIXEL_Y * y);
			x++;
		}
		y++;
	}
	//mlx_string_put(g.mlx, g.win, 32, 32, 0xFFFFFF, "Hello");
}
