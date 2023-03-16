/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:36:54 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 15:50:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	destroy_game(t_game *g)
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
}

static void	reset_game(t_game *g)
{
	g->frame = 0;
	if (!set_map(g, g->map_path))
		raise_error("ERROR\n");
	set_player(g);
	set_enemy(g);
	set_exit(g);
	set_collectibles(g);
	g->key = init_key();
}

void	restart_game(t_game *g)
{
	destroy_game(g);
	reset_game(g);
}
