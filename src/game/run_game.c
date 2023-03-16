/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:49:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 22:52:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	run_game(t_game *g)
{
	if (g->key.esc)
		close_game(g);
	if (g->key.r || (g->player.status == DEAD && (g->frame - g->player.frame_dead > 50)))
		restart_game(g);
	g->frame++;
	move_player(g);
	move_enemy(g);
	move_exit(g);
	if (g->player.status != DEAD && is_overlapped(g->player.pos, g->enemy.pos))
	{
		g->player.status = DEAD;
		g->player.frame_dead = g->frame;
		g->player.v.y = 0;
		g->player.remaining = 96;
	}
	update_collectibles(g);
	if (check_game_clear(g))
		close_game(g);
	draw_game(*g);
	return (0);
}
