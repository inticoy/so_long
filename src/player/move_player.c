/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:06:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/07 16:24:53 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	acceleration_x(t_game *g)
{
	g->player.a.x = 0;
	if (g->key.press_d)
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
	if (g->key.press_a)
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

static void	acceleration_y(t_game *g)
{
	g->player.a.y = 0;
	if (g->key.press_w)
	{
		if (g->player.remaining > 0 && -12 < g->player.v.y && g->player.v.y <= 0)
			g->player.a.y = -8;
		else if (g->player.remaining > 0 && -12 == g->player.v.y)
			g->player.a.y = -2;
	}
	g->player.a.y += 2;
}

static void	block_x(t_game *g)
{
	int		blocked_x;
	t_point	next_x;

	blocked_x = 0;
	next_x = init_point(g->player.pos.x + g->player.v.x, g->player.pos.y);
	if ('1' == g->map.map[next_x.y / 32][next_x.x / 32])
		blocked_x = 1;
	if ('1' == g->map.map[next_x.y / 32][(next_x.x + 31) / 32])
		blocked_x = 1;
	if ('1' == g->map.map[(next_x.y + 31) / 32][next_x.x / 32])
		blocked_x = 1;
	if ('1' == g->map.map[(next_x.y + 31) / 32][(next_x.x + 31) / 32])
		blocked_x = 1;
	if (blocked_x)
		g->player.v.x = 0;
	else
		g->player.pos.x += g->player.v.x;
}

static void	block_y(t_game *g)
{
	int		blocked_y;
	t_point	next_y;

	blocked_y = 0;
	next_y = init_point(g->player.pos.x, g->player.pos.y + g->player.v.y);
	if ('1' == g->map.map[next_y.y / 32][next_y . x/32])
	{
		blocked_y = 1;
		g->player.remaining = 0;
	}
	if ('1' == g->map.map[next_y.y / 32][(next_y.x + 31) / 32])
	{
		blocked_y = 1;
		g->player.remaining = 0;
	}
	if ('1' == g->map.map[(next_y.y + 31) / 32][next_y.x / 32])
	{
		blocked_y = 1;
		g->player.remaining = 96;
	}
	if ('1' == g->map.map[(next_y.y + 31) / 32][(next_y.x + 31) / 32])
	{
		blocked_y = 1;
		g->player.remaining = 96;
	}
	if (blocked_y)
		g->player.v.y = 0;
	else
	{
		g->player.pos.y += g->player.v.y;
		g->player.remaining += g->player.v.y;
	}
}

void	move_player(t_game *g)
{
    acceleration_x(g);
	g->player.v.x += g->player.a.x;
	acceleration_y(g);
	if (g->player.v.y + g->player.a.y >= -12 && g->player.v.y + g->player.a.y <= 12)
		g->player.v.y += g->player.a.y;
	block_x(g);
	block_y(g);
}
