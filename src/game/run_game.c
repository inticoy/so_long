/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:49:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/17 16:27:55 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	run_game(t_game *g)
{
	if (g->key.esc)
		close_game(g);
	if (g->key.r \
		|| (g->player.status == DEAD && (g->frame - g->player.frame_dead > 50)))
		restart_game(g);
	g->frame++;
	move_player(g);
	move_enemy(g);
	move_exit(g);
	if (g->player.status != DEAD && \
		g->enemy.status != DEAD && \
		is_overlapped(g->player.pos, g->enemy.pos))
	{
		if (g->player.v.y > 0)
			kill_enemy(g);
		else
			kill_player(g);
	}
	update_collectibles(g);
	if (check_game_clear(g))
		close_game(g);
	draw_game(*g);
	return (0);
}
