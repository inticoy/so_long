/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:55:18 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 15:31:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

t_bool	is_rectangle(t_map map)
{
	int	y;

	y = 0;
	while (y < map.size.y)
	{
		if (map.size.x != (int)ft_strlen(map.map[y]) - 1)
			return (ft_false);
		y++;
	}
	return (ft_true);
}
