/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:53:22 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:47:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"

void	draw_exit(t_game g)
{
	if (g.clear)
		mlx_put_image_to_window(g.mlx, g.win, \
							g.assets.item[3].img, \
							g.exit.pos.x, g.exit.pos.y);
	else
		mlx_put_image_to_window(g.mlx, g.win, \
							g.assets.exit.img, \
							g.exit.pos.x, g.exit.pos.y);
}
