/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:26:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/08 16:17:11 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

t_game	init_game(char *map_path)
{
	t_game	g;

	g.frame = 0;
	g.mlx = mlx_init();
	set_map(&g, map_path);
	set_player(&g);
	set_enemy(&g);
	set_exit(&g);
	set_collectibles(&g);
	g.assets = read_assets(g.mlx);
	g.size = init_point(PIXEL_X * g.map.size.x, PIXEL_Y * g.map.size.y);
	g.win = mlx_new_window(g.mlx, g.size.x, g.size.y, TITLE);
	g.key = init_key();
	return (g);
}
