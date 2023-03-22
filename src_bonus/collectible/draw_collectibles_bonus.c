/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectibles_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:49:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:47:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
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
