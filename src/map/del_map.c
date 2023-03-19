/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:42:03 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/19 20:23:27 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	del_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->size.y)
	{
		ft_free_s(map->map[y]);
		ft_free_s(map->data[y]);
		y++;
	}
	ft_free_s(map->map);
	ft_free_s(map->data);
	map->map = 0;
	map->data = 0;
}
