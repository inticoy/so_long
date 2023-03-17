/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:14:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/17 14:14:16 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	kill_player(t_game *g)
{
	g->player.status = DEAD;
	g->player.frame_dead = g->frame;
	g->player.v.y = 0;
	g->player.remaining = 96;
}
