/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:42:03 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:47:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

void	del_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->size.y)
	{
		if (map->map)
			ft_free_s(map->map[y]);
		if (map->data)
			ft_free_s(map->data[y]);
		y++;
	}
	ft_free_s(map->map);
	ft_free_s(map->data);
	map->map = 0;
	map->data = 0;
}
