/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:49:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:47:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"

void	draw_enemy(t_game g)
{
	if (g.enemy.status == DEAD)
	{
		if (g.frame - g.enemy.frame_dead < 8)
			mlx_put_image_to_window(g.mlx, g.win, g.assets.enemy[2].img, \
									g.enemy.pos.x, g.enemy.pos.y);
	}
	else
		mlx_put_image_to_window(g.mlx, g.win, \
								g.assets.enemy[(g.frame / 8) % 2].img, \
								g.enemy.pos.x, g.enemy.pos.y);
}
