/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:53:22 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/06 19:40:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	draw_exit(t_game g)
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
			if (g.map.map[y][x] == 'E')
			{
				img = g.assets.peach.img;
				mlx_put_image_to_window(g.mlx, g.win, img, PX_X * x, PX_Y * y);
			}
			x++;
		}
		y++;
	}
}
