/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:06:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 15:30:32 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static void	animate_dead(t_game *g)
{
	if (g->player.status == DEAD)
	{
		g->player.a.x = 0;
		g->player.v.x = 0;
		g->key.w = ft_true;
		g->key.a = ft_false;
		g->key.s = ft_false;
		g->key.d = ft_false;
	}
}

static void	animate_kill(t_game *g)
{
	if (g->player.status != DEAD && g->enemy.status == DEAD)
	{
		if (g->frame - g->enemy.frame_dead < 2)
		{
			g->key.w = ft_true;
			g->key.s = ft_false;
		}
		else if (g->frame - g->enemy.frame_dead == 2)
			g->key.w = ft_false;
	}
}

void	move_player(t_game *g)
{
	animate_dead(g);
	animate_kill(g);
	update_player_a(g);
	update_player_v(g);
	update_player_pos(g);
	if (has_movement(g))
		g->player.movement++;
}
