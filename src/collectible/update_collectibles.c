/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_collectibles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:43:42 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/08 15:56:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_collectibles(t_game *g)
{
	t_list	*node;
	t_point	pos;

	node = g->collectibles;
	while (node)
	{
		pos = ((t_collectible *)node->content)->pos;
		if (is_overlapped(g->player.pos, pos))
			((t_collectible *)node->content)->is_collected = ft_true;
		node = node->next;
	}
}
