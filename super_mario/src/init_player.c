/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:30:12 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/01 14:45:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	init_player(t_map m)
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
			if (m.map[y][x] == 'P')
				p.pos = init_point(x * PX_X, y * PX_Y);
			x++;
		}
		y++;
	}
	p.is_left = ft_false;
	p.remaining = 96;
	p.v = init_point(0, 0);
	p.a = init_point(0, 0);
	return (p);
}
