/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemy_v.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:45:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/17 13:56:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_enemy_v(t_game *g)
{
	if (g->enemy.status == RIGHT)
		g->enemy.v.x = 2;
	else if (g->enemy.status == LEFT)
		g->enemy.v.x = -2;
	else if (g->enemy.status == DEAD)
		g->enemy.v.x = 0;
	if (-12 <= g->enemy.v.y + g->enemy.a.y && g->enemy.v.y + g->enemy.a.y <= 12)
		g->enemy.v.y += g->enemy.a.y;
}
