/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_collectibles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:40:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/08 15:53:14 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	set_collectibles(t_game *g)
{
	t_collectible	*collectible;
	t_list			*head;
	int				x;
	int				y;

	head = FT_NULL;
	y = 0;
	while (g->map.map[y])
	{
		x = 0;
		while (x < g->map.size.x)
		{
			if (g->map.map[y][x] == 'C')
			{
				collectible = (t_collectible *) \
							ft_calloc(1, sizeof(t_collectible));
				collectible->pos.x = x * PX_X;
				collectible->pos.y = y * PX_Y;
				ft_lstadd_back(&head, ft_lstnew(collectible));
			}
			x++;
		}
		y++;
	}
	g->collectibles = head;
}
