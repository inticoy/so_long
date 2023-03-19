/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:55:18 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/19 20:24:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

t_bool	is_rectangle(t_map map)
{
	int	y;

	y = 0;
	while (y < map.size.y)
	{
		if (map.size.x != ft_strlen(map.map[y]) - 1)
			return (ft_false);
		y++;
	}
	return (ft_true);
}
