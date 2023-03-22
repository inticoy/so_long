/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:55:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 15:31:44 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

t_bool	is_surrounded(t_map map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.size.y)
	{
		x = 0;
		while (x < (int)ft_strlen(map.map[y]) - 1)
		{
			if (x == 0 || x == map.size.x - 1 || y == 0 || y == map.size.y - 1)
				if (map.map[y][x] != '1')
					return (ft_false);
			x++;
		}
		y++;
	}
	return (ft_true);
}
