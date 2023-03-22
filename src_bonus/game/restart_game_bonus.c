/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:36:54 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:47:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

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
	g->frame_clear = 0;
	g->clear = ft_false;
	if (!set_map(g, g->map_path))
		raise_error("error\n");
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
