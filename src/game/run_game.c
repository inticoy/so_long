/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:49:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 20:57:04 by gyoon            ###   ########.fr       */
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
	if (is_overlapped(g->player.pos, g->enemy.pos))
	{
		g->player.status = DEAD;
		g->player.frame_dead = g->frame;
	}
	update_collectibles(g);
	//check_game_clear(g);
	draw_game(*g);
	return (0);
}
