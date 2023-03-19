/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:46:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/19 21:39:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	draw_player(t_game g)
{
	int	status;
	int	i;

	if (g.clear)
		return ;
	if (g.player.status == LEFT)
		status = 0;
	else if (g.player.status == RIGHT)
		status = 1;
	else
		status = 2;
	if (g.player.v.y || g.player.remaining < 0)
		i = 5;
	else if ((g.player.status == RIGHT && g.player.v.x > 0) \
			|| (g.player.status == LEFT && g.player.v.x < 0))
		i = 1 + (g.frame / 8) % 3;
	else if ((g.player.status == RIGHT && g.player.v.x < 0) \
			|| (g.player.status == LEFT && g.player.v.x > 0))
		i = 4;
	else
		i = 0;
	mlx_put_image_to_window(g.mlx, g.win, g.assets.player[status][i].img, \
							g.player.pos.x, g.player.pos.y);
}
