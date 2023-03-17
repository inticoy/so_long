/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:14:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/17 14:46:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	kill_enemy(t_game *g)
{
	g->enemy.status = DEAD;
	g->enemy.frame_dead = g->frame;
	g->player.v.y = 0;
	g->player.remaining = 8;
}
