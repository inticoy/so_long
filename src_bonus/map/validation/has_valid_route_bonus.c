/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_route_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:55:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:47:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

void	traverse_map(t_map map, t_point p)
{
	map.map[p.y][p.x] *= -1;
	if (map.map[p.y - 1][p.x] != '1' && ft_isascii(map.map[p.y - 1][p.x]))
		traverse_map(map, init_point(p.x, p.y - 1));
	if (map.map[p.y + 1][p.x] != '1' && ft_isascii(map.map[p.y + 1][p.x]))
		traverse_map(map, init_point(p.x, p.y + 1));
	if (map.map[p.y][p.x - 1] != '1' && ft_isascii(map.map[p.y][p.x - 1]))
		traverse_map(map, init_point(p.x - 1, p.y));
	if (map.map[p.y][p.x + 1] != '1' && ft_isascii(map.map[p.y][p.x + 1]))
		traverse_map(map, init_point(p.x + 1, p.y));
	return ;
}

t_bool	has_alpha(t_map map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.size.y)
	{
		x = 0;
		while (x < map.size.x)
		{
			if (ft_isalpha(map.map[y][x]))
				return (ft_true);
			x++;
		}
		y++;
	}
	return (ft_false);
}

void	undo_traverse(t_map map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.size.y)
	{
		x = 0;
		while (x < map.size.x)
		{
			if (!ft_isascii(map.map[y][x]))
				map.map[y][x] *= -1;
			x++;
		}
		y++;
	}
}

t_bool	has_valid_route(t_map map)
{
	t_point	pos_player;
	t_bool	ret;

	pos_player = find_player(map);
	traverse_map(map, pos_player);
	ret = !has_alpha(map);
	undo_traverse(map);
	return (ret);
}
