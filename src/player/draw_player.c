/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:46:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/06 19:37:38 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	draw_player(t_game g)
{
	int	i;
	int	j;

	if (g.player.status == LEFT)
		i = 0;
	else if (g.player.status == RIGHT)
		i = 1;
	else if (g.player.status == DEAD)
		i = 2;
	if (g.player.remaining != 96)
	// if (g.player.v.y)
		j = 5;
	else if ((g.player.status == RIGHT && g.player.v.x > 0) \
			|| (g.player.status == LEFT && g.player.v.x < 0))
		j = 1 + (g.frame / 8) % 3;
	else if ((g.player.status == RIGHT && g.player.v.x < 0) \
			|| (g.player.status == LEFT && g.player.v.x > 0))
		j = 4;
	else
		j = 0;
	mlx_put_image_to_window(g.mlx, g.win, g.assets.player[i][j].img, g.player.pos.x, g.player.pos.y);
}