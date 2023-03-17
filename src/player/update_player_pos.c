/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:45:12 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/17 16:14:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	check_x_blocked(t_game *g)
{
	t_bool	x_blocked;
	t_point	next_x;

	x_blocked = ft_false;
	next_x = init_point(g->player.pos.x + g->player.v.x, g->player.pos.y);
	if ('3' > g->map.map[(next_x.y + 4) / UNIT_Y][(next_x.x + 3) / UNIT_X])
		x_blocked = ft_true;
	if ('3' > g->map.map[(next_x.y + 4) / UNIT_Y][(next_x.x + 28) / UNIT_X])
		x_blocked = ft_true;
	if ('3' > g->map.map[(next_x.y + 31) / UNIT_Y][(next_x.x + 3) / UNIT_X])
		x_blocked = ft_true;
	if ('3' > g->map.map[(next_x.y + 31) / UNIT_Y][(next_x.x + 28) / UNIT_X])
		x_blocked = ft_true;
	if (x_blocked)
		g->player.v.x = 0;
	return (x_blocked);
}

static t_bool	check_y_blocked(t_game *g)
{
	t_bool	y_blocked;
	t_point	next_y;

	y_blocked = ft_false;
	next_y = init_point(g->player.pos.x, g->player.pos.y + g->player.v.y);
	if (('3' > g->map.map[(next_y.y + 4) / UNIT_Y][(next_y.x + 3) / UNIT_X]) \
	|| ('3' > g->map.map[(next_y.y + 4) / UNIT_Y][(next_y.x + 28) / UNIT_X]))
	{
		y_blocked = ft_true;
		g->player.remaining = 0;
	}
	if (('3' > g->map.map[(next_y.y + 31) / UNIT_Y][(next_y.x + 3) / UNIT_X]) \
	|| ('3' > g->map.map[(next_y.y + 31) / UNIT_Y][(next_y.x + 28) / UNIT_X]))
	{
		y_blocked = ft_true;
		g->player.remaining = 96;
	}
	if (y_blocked)
		g->player.v.y = 0;
	return (y_blocked);
}

void	update_player_pos(t_game *g)
{
	if ((g->player.status == DEAD) || !check_x_blocked(g))
		g->player.pos.x += g->player.v.x;
	if ((g->player.status == DEAD) || !check_y_blocked(g))
	{
		g->player.pos.y += g->player.v.y;
		g->player.remaining += g->player.v.y;
	}
}