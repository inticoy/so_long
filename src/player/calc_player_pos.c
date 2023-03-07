/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:33:52 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/07 21:40:55 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	calc_player_pos(t_game *g)
{
	block_x(g);
	block_y(g);
}
