/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:53:22 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/08 14:35:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	draw_exit(t_game g)
{
	mlx_put_image_to_window(g.mlx, g.win, g.assets.peach.img, g.exit.pos.x, g.exit.pos.y);
}
