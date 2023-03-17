/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:44:35 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/17 13:54:16 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy	init_enemy(t_map m)
{
	t_enemy	enemy;
	int		x;
	int		y;

	y = 0;
	while (y < m.size.y)
	{
		x = 0;
		while (x < m.size.x)
		{
			if (m.map[y][x] == 'E')
				enemy.pos = init_point(x * UNIT_X, y * UNIT_Y);
			x++;
		}
		y++;
	}
	enemy.status = RIGHT;
	enemy.remaining = 96;
	enemy.v = init_point(0, 0);
	enemy.a = init_point(0, 0);
	enemy.movement = 0;
	enemy.frame_dead = 0;
	return (enemy);
}
