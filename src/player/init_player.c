/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:30:12 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 17:14:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	init_player(t_map m)
{
	t_player	p;

	p.pos = find_player(m);
	p.pos.x *= UNIT_X;
	p.pos.y *= UNIT_Y;
	p.status = 1;
	p.remaining = 96;
	p.v = init_point(0, 0);
	p.a = init_point(0, 0);
	p.movement = 0;
	p.frame_dead = 0;
	return (p);
}
