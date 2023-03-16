/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:22:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 22:45:08 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player_a_x(t_game *g)
{
	g->player.a.x = 0;
	if (g->key.d)
	{
		g->player.status = RIGHT;
		if (0 <= g->player.v.x && g->player.v.x < 4 && g->frame % 2 == 0)
			g->player.a.x = 1;
	}
	else
	{
		if (g->player.v.x > 0 && g->frame % 8 == 0)
			g->player.a.x = -1;
	}
	if (g->key.a)
	{
		g->player.status = LEFT;
		if (-4 < g->player.v.x && g->player.v.x <= 0 && g->frame % 2 == 0)
			g->player.a.x = -1;
	}
	else
	{
		if (g->player.v.x < 0 && g->frame % 8 == 0)
			g->player.a.x = 1;
	}
}

static void	update_player_a_y(t_game *g)
{
	g->player.a.y = 0;
	if (g->key.w)
	{
		if (g->player.remaining > 0 && -12 < g->player.v.y && g->player.v.y <= 0)
			g->player.a.y = -8;
		else if (g->player.remaining > 0 && -12 == g->player.v.y)
			g->player.a.y = -2;
	}
	g->player.a.y += 2;
}

void	update_player_a(t_game *g)
{
	update_player_a_x(g);
	update_player_a_y(g);
}
