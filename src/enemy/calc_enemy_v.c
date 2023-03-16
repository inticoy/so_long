/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_enemy_v.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:09:41 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 22:14:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calc_enemy_v(t_game *g)
{
	if (g->enemy.status == RIGHT)
		g->enemy.v.x = 2;
	else if (g->enemy.status == LEFT)
		g->enemy.v.x = -2;
	if (-12 <= g->enemy.v.y + g->enemy.a.y && g->enemy.v.y + g->enemy.a.y <= 12)
		g->enemy.v.y += g->enemy.a.y;
}
