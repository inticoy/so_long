/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:06:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 20:43:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	dead_player(t_game *g)
{
	if (g->player.status == DEAD)
	{
		g->player.a.x = 0;
		g->player.v.x = 0;
		g->key.w = ft_true;
		g->key.a = ft_false;
		g->key.s = ft_false;
		g->key.d = ft_false;
	}
}

void	move_player(t_game *g)
{
	dead_player(g);
	calc_player_a(g);
	calc_player_v(g);
	calc_player_pos(g);
	if (has_movement(g))
		g->player.movement++;
}
