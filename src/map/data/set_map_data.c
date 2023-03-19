/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:15:24 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/19 20:20:23 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	set_map_data(t_map *map)
{
	int	y;

	map->data = (t_map_data **)ft_calloc(map->size.y, sizeof(t_map_data *));
	y = 0;
	while (y < map->size.y)
	{
		map->data[y] = (t_map_data *)ft_calloc(map->size.x, sizeof(t_map_data));
		y++;
	}
}
