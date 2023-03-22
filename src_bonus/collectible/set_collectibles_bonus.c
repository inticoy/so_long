/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_collectibles_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:40:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:47:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

void	set_collectibles(t_game *g)
{
	t_collectible	*collectible;
	t_list			*head;
	int				x;
	int				y;

	head = FT_NULL;
	y = 0;
	while (y < g->map.size.y)
	{
		x = 0;
		while (x < g->map.size.x)
		{
			if (g->map.map[y][x] == 'C')
			{
				collectible = (t_collectible *) \
							ft_calloc(1, sizeof(t_collectible));
				collectible->pos.x = x * UNIT_X;
				collectible->pos.y = y * UNIT_Y;
				ft_lstadd_back(&head, ft_lstnew(collectible));
			}
			x++;
		}
		y++;
	}
	g->collectibles = head;
}
