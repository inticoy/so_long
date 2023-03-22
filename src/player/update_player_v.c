/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_v.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:45:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 15:30:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_v(t_game *g)
{
	g->player.v.x += g->player.a.x;
	if (-12 <= g->player.v.y + g->player.a.y && \
		g->player.v.y + g->player.a.y <= 12)
		g->player.v.y += g->player.a.y;
}
