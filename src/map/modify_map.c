/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:57:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/19 19:51:05 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_sky(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			if (map->map[y][x] == '0')
				map->map[y][x] = '3';
			x++;
		}
		y++;
	}
}

static int	change_into_ground(t_map *map)
{
	int	ground;
	int	count;
	int	x;

	ground = map->size.y - 1;
	while (ground > 0)
	{
		count = 0;
		x = 0;
		while (x < map->size.x)
		{
			if (map->map[ground][x] > '2')
				count++;
			x++;
		}
		if (count)
			return (ground);
		while (x > 0)
		{
			map->map[ground][x - 1] = '0';
			x--;
		}
		ground--;
	}
	return (ground);
}

static void	change_into_stair(t_map *map, int ground)
{
	int	x;
	int	y;

	x = 1;
	while (x < map->size.x - 1)
	{
		y = ground;
		while (y > 0)
		{
			if (map->map[y][x] == '1')
				map->map[y][x] = '2';
			else
				break ;
			y--;
		}
		x++;
	}
	return ;
}

void	modify_map(t_map *map)
{
	int	ground;

	change_sky(map);
	ground = change_into_ground(map);
	change_into_stair(map, ground);
}
