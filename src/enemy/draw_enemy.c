/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:49:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/06 19:51:38 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	draw_enemy(t_game g)
{
	int	i;

	if (g.enemy.status == LEFT)
		i = 0;
	else if (g.enemy.status == RIGHT)
		i = 1;
	else if (g.enemy.status == DEAD)
		i = 2;
	mlx_put_image_to_window(g.mlx, g.win, g.assets.enemy[i].img, g.enemy.pos.x, g.enemy.pos.y);
}
