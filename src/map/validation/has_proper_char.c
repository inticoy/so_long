/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_proper_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:22:37 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/15 16:55:39 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

t_bool	has_proper_char(t_map map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map.size.y)
	{
		x = 0;
		while (x < ft_strlen(map.map[y]) - 1)
		{
			if (map.map[y][x] != '0' && \
				map.map[y][x] != '1' && \
				map.map[y][x] != 'C' && \
				map.map[y][x] != 'E' && \
				map.map[y][x] != 'P')
				return (ft_false);
			x++;
		}
		y++;
	}
	return (ft_true);
}
