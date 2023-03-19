/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:49:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/19 17:07:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include "mlx.h"

void	draw_collectibles(t_game g)
{
	while (g.collectibles)
	{
		if (!((t_collectible *)g.collectibles->content)->is_collected)
			mlx_put_image_to_window(g.mlx, g.win, \
						g.assets.item[(g.frame / 10) % 3].img, \
						((t_collectible *)g.collectibles->content)->pos.x, \
						((t_collectible *)g.collectibles->content)->pos.y);
		g.collectibles = g.collectibles->next;
	}
}
