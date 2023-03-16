/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemy_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:45:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 22:45:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	check_x_blocked(t_game *g)
{
	t_bool	x_blocked;
	t_point	next_x;

	x_blocked = ft_false;
	next_x = init_point(g->enemy.pos.x + g->enemy.v.x, g->enemy.pos.y);
	if ('1' == g->map.map[(next_x.y + 4) / UNIT_Y][(next_x.x + 3) / UNIT_X])
		x_blocked = ft_true;
	if ('1' == g->map.map[(next_x.y + 4) / UNIT_Y][(next_x.x + 28) / UNIT_X])
		x_blocked = ft_true;
	if ('1' == g->map.map[(next_x.y + 31) / UNIT_Y][(next_x.x + 3) / UNIT_X])
		x_blocked = ft_true;
	if ('1' == g->map.map[(next_x.y + 31) / UNIT_Y][(next_x.x + 28) / UNIT_X])
		x_blocked = ft_true;
	if (x_blocked)
		g->enemy.v.x = 0;
	return (x_blocked);
}

static t_bool	check_y_blocked(t_game *g)
{
	t_bool	y_blocked;
	t_point	next_y;

	y_blocked = ft_false;
	next_y = init_point(g->enemy.pos.x, g->enemy.pos.y + g->enemy.v.y);
	if (('1' == g->map.map[(next_y.y + 4) / UNIT_Y][(next_y.x + 3) / UNIT_X]) \
	|| ('1' == g->map.map[(next_y.y + 4) / UNIT_Y][(next_y.x + 28) / UNIT_X]))
	{
		y_blocked = ft_true;
		g->enemy.remaining = 0;
	}
	if (('1' == g->map.map[(next_y.y + 31) / UNIT_Y][(next_y.x + 3) / UNIT_X]) \
	|| ('1' == g->map.map[(next_y.y + 31) / UNIT_Y][(next_y.x + 28) / UNIT_X]))
	{
		y_blocked = ft_true;
		g->enemy.remaining = 96;
	}
	if (y_blocked)
		g->enemy.v.y = 0;
	return (y_blocked);
}

void	update_enemy_pos(t_game *g)
{
	if (!check_x_blocked(g))
		g->enemy.pos.x += g->enemy.v.x;
	else
		g->enemy.status *= -1;
	if (!check_y_blocked(g))
	{
		g->enemy.pos.y += g->enemy.v.y;
		g->enemy.remaining += g->enemy.v.y;
	}
}
