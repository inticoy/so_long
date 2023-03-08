/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_remaining_collectibles.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:59:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/08 16:01:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_remaining_collectibles(t_game *g)
{
	int		remaining;
	t_list	*node;

	remaining = 0;
	node = g->collectibles;
	while (node)
	{
		if (!((t_collectible *)node->content)->is_collected)
			remaining++;
		node = node->next;
	}
	return (remaining);
}
