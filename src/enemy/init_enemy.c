/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:44:35 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 22:13:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy init_enemy(t_map m)
{
	t_player	p;
	int			x;
	int			y;

	y = 0;
	while (y < m.size.y)
	{
		x = 0;
		while (x < m.size.x)
		{
			if (m.map[y][x] == 'E')
				p.pos = init_point(x * UNIT_X, y * UNIT_Y);
			x++;
		}
		y++;
	}
	p.status = RIGHT;
	p.remaining = 96;
	p.v = init_point(0, 0);
	p.a = init_point(0, 0);
	return (p);
}
