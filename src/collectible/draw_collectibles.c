/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:49:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/07 14:14:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include "mlx.h"

void	draw_collectibles(t_game g)
{
	while (g.collectibles)
	{
		mlx_put_image_to_window(g.mlx, g.win, g.assets.collectible[(g.frame / 10) % 3].img, \
								((t_collectible *)g.collectibles->content)->pos.x * PX_X, \
								((t_collectible *)g.collectibles->content)->pos.y * PX_Y);
		g.collectibles = g.collectibles->next;
	}
}
