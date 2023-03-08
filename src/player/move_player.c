/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:06:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/08 15:27:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	move_player(t_game *g)
{
	calc_player_a(g);
	calc_player_v(g);
	calc_player_pos(g);
	ft_printf("v : %d\n", g->player.v.y);
}
