/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:55:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/15 15:56:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

t_bool	is_playable(t_map map)
{
	int	ch_count[3];
	int	x;

	ch_count[0] = 0;
	ch_count[1] = 0;
	ch_count[2] = 0;
	while (*map.map)
	{
		x = 0;
		while (x < ft_strlen(*map.map) - 1)
		{
			if ((*map.map)[x] == 'C')
				ch_count[0]++;
			else if ((*map.map)[x] == 'E')
				ch_count[1]++;
			else if ((*map.map)[x] == 'P')
				ch_count[2]++;
			x++;
		}
		map.map++;
	}
	if (ch_count[0] > 0 && ch_count[1] == 1 && ch_count[2] == 1)
		return (ft_true);
	else
		return (ft_false);
}
