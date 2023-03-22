/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_exit_pos_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:45:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:47:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_bool	check_x_blocked(t_game *g)
{
	t_bool	x_blocked;
	t_point	next_x;

	x_blocked = ft_false;
	next_x = init_point(g->exit.pos.x + g->exit.v.x, g->exit.pos.y);
	if ('3' > g->map.map[(next_x.y + 4) / UNIT_Y][(next_x.x + 3) / UNIT_X])
		x_blocked = ft_true;
	if ('3' > g->map.map[(next_x.y + 4) / UNIT_Y][(next_x.x + 28) / UNIT_X])
		x_blocked = ft_true;
	if ('3' > g->map.map[(next_x.y + 31) / UNIT_Y][(next_x.x + 3) / UNIT_X])
		x_blocked = ft_true;
	if ('3' > g->map.map[(next_x.y + 31) / UNIT_Y][(next_x.x + 28) / UNIT_X])
		x_blocked = ft_true;
	if (x_blocked)
		g->exit.v.x = 0;
	return (x_blocked);
}

static t_bool	check_y_blocked(t_game *g)
{
	t_bool	y_blocked;
	t_point	next_y;

	y_blocked = ft_false;
	next_y = init_point(g->exit.pos.x, g->exit.pos.y + g->exit.v.y);
	if (('3' > g->map.map[(next_y.y + 4) / UNIT_Y][(next_y.x + 3) / UNIT_X]) \
	|| ('3' > g->map.map[(next_y.y + 4) / UNIT_Y][(next_y.x + 28) / UNIT_X]))
	{
		y_blocked = ft_true;
		g->exit.remaining = 0;
	}
	if (('3' > g->map.map[(next_y.y + 31) / UNIT_Y][(next_y.x + 3) / UNIT_X]) \
	|| ('3' > g->map.map[(next_y.y + 31) / UNIT_Y][(next_y.x + 28) / UNIT_X]))
	{
		y_blocked = ft_true;
		g->exit.remaining = 96;
	}
	if (y_blocked)
		g->exit.v.y = 0;
	return (y_blocked);
}

void	update_exit_pos(t_game *g)
{
	if (!check_x_blocked(g))
		g->exit.pos.x += g->exit.v.x;
	else
		g->exit.status *= -1;
	if (!check_y_blocked(g))
	{
		g->exit.pos.y += g->exit.v.y;
		g->exit.remaining += g->exit.v.y;
	}
}
