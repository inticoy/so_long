/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:21:17 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/08 14:35:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	draw_game(t_game g)
{
	mlx_clear_window(g.mlx, g.win);
	draw_map(g);
	draw_exit(g);
	draw_player(g);
	draw_enemy(g);
	draw_collectibles(g);
}
