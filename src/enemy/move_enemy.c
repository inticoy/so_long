/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:29:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/08 15:16:05 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	acceleration_y(t_game *g)
{
	g->enemy.a.y = 2;
}

static void	block_x(t_game *g)
{
	int		blocked_x;
	t_point	next_x;

	blocked_x = 0;
	next_x = init_point(g->enemy.pos.x + g->enemy.v.x, g->enemy.pos.y);
	if ('1' == g->map.map[next_x.y / 32][next_x.x / 32])
		blocked_x = 1;
	if ('1' == g->map.map[next_x.y / 32][(next_x.x + 31) / 32])
		blocked_x = 1;
	if ('1' == g->map.map[(next_x.y + 31) / 32][next_x.x / 32])
		blocked_x = 1;
	if ('1' == g->map.map[(next_x.y + 31) / 32][(next_x.x + 31) / 32])
		blocked_x = 1;
	if (blocked_x)
		g->enemy.v.x = 0;
	else
		g->enemy.pos.x += g->enemy.v.x;
}

static void	block_y(t_game *g)
{
	int		blocked_y;
	t_point	next_y;

	blocked_y = 0;
	next_y = init_point(g->enemy.pos.x, g->enemy.pos.y + g->enemy.v.y);
	if ('1' == g->map.map[next_y.y / 32][next_y.x / 32])
	{
		blocked_y = 1;
		g->enemy.remaining = 0;
	}
	if ('1' == g->map.map[next_y.y / 32][(next_y.x + 31) / 32])
	{
		blocked_y = 1;
		g->enemy.remaining = 0;
	}
	if ('1' == g->map.map[(next_y.y + 31) / 32][next_y.x / 32])
	{
		blocked_y = 1;
		g->enemy.remaining = 96;
	}
	if ('1' == g->map.map[(next_y.y + 31) / 32][(next_y.x + 31) / 32])
	{
		blocked_y = 1;
		g->enemy.remaining = 96;
	}
	if (blocked_y)
		g->enemy.v.y = 0;
	else
	{
		g->enemy.pos.y += g->enemy.v.y;
		g->enemy.remaining += g->enemy.v.y;
	}
}

void	move_enemy(t_game *g)
{
	g->enemy.v.x = -2;
	acceleration_y(g);
	if (g->enemy.v.y + g->enemy.a.y >= -12 && g->enemy.v.y + g->enemy.a.y <= 12)
		g->enemy.v.y += g->enemy.a.y;
	block_x(g);
	block_y(g);
}
