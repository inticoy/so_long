/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_player_v.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:39:24 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/08 15:39:56 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calc_player_v(t_game *g)
{
	g->player.v.x += g->player.a.x;
	if (-12 <= g->player.v.y + g->player.a.y && g->player.v.y + g->player.a.y <= 12)
		g->player.v.y += g->player.a.y;
}
