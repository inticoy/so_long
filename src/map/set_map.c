/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:33:32 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 15:20:38 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_map(t_game *g, char *map_path)
{
	int	y;

	y = 0;
	if (!validate_map_path(map_path))
		return (0);
	g->map = read_map(map_path);
	if (!validate_map(g->map))
	{
		while (y < g->map.size.y)
		{
			ft_free_s(g->map.map[y]);
			y++;
		}
		ft_free_s(g->map.map);
		g->map.map = 0;
		return (0);
	}
	return (1);
}
