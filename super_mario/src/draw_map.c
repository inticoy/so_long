/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:39:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/01 15:22:23 by gyoon            ###   ########.fr       */
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
			mlx_put_image_to_window(g.mlx, g.win, img, PX_X * x, PX_Y * y);
			i = 0;
			if (g.map.map[y][x] == '1')
				i = 3;
			else if (g.map.map[y][x] == 'C')
				i = 9 + (pow((5 - (g.frame / 8) % 6), 2) + pow(((g.frame / 8) % 6), 2)) / 8;
			else if (g.map.map[y][x] == '2')
				i = 13;
			img = g.assets.block[i].img;
			mlx_put_image_to_window(g.mlx, g.win, img, PX_X * x, PX_Y * y);
			x++;
		}
		y++;
	}
}
