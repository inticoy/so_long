/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:12:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/19 19:28:42 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_game(t_game *g)
{
	if (check_game_clear(g) && !g->clear)
	{
		g->clear = ft_true;
		g->frame_clear = g->frame;
	}
	if (g->clear && g->frame - g->frame_clear > 50)
		close_game(g);
}
