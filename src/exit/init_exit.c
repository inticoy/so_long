/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:29:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/08 16:50:58 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_exit	init_exit(t_map m)
{
	t_exit	p;
	int		x;
	int		y;

	y = 0;
	while (y < m.size.y)
	{
		x = 0;
		while (x < m.size.x)
		{
			if (m.map[y][x] == 'E')
				p.pos = init_point(x * BLOCK_X, y * BLOCK_Y);
			x++;
		}
		y++;
	}
	p.status = LEFT;
	p.remaining = 96;
	p.v = init_point(0, 0);
	p.a = init_point(0, 0);
	return (p);
}
