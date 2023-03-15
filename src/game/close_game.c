/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:25:18 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/15 17:20:29 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	close_game(t_game *g)
{
	int	y;

	y = 0;
	while (y < g->map.size.y)
	{
		ft_free_s(g->map.map[y]);
		y++;
	}
	ft_free_s(g->map.map);
	g->map.map = 0;
	ft_lstclear(&g->collectibles, ft_free_s);
	exit(1);
}
