/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:26:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/31 17:05:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

t_game	init_game(char *map_path)
{
	t_game	g;

	g.frame = 0;
	g.mlx = mlx_init();
	g.map = read_map(map_path);
	g.player = init_player(g.map);
	g.assets = read_assets(g.mlx);
	g.size = init_point(BLOCK_X * g.map.size.x, BLOCK_Y * g.map.size.y);
	g.win = mlx_new_window(g.mlx, g.size.x, g.size.y, TITLE);
	g.key = init_key();
	return (g);
}