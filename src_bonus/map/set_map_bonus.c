/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:33:32 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:47:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	set_map(t_game *g, char *map_path)
{
	if (!validate_map_path(map_path))
		return (0);
	g->map = read_map(map_path);
	if (!validate_map(g->map))
	{
		del_map(&g->map);
		return (0);
	}
	modify_map(&g->map);
	set_map_data(&g->map);
	return (1);
}
