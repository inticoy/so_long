/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:55:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/19 20:26:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	set_zero(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		arr[i] = 0;
		i++;
	}
}

t_bool	is_playable(t_map map)
{
	int	ch_count[3];
	int	x;
	int	y;

	set_zero(ch_count, 3);
	y = 0;
	while (y < map.size.y)
	{
		x = 0;
		while (x < ft_strlen(map.map[y]) - 1)
		{
			if ((map.map[y])[x] == 'C')
				ch_count[0]++;
			else if ((map.map[y])[x] == 'E')
				ch_count[1]++;
			else if ((map.map[y])[x] == 'P')
				ch_count[2]++;
			x++;
		}
		y++;
	}
	if (ch_count[0] > 0 && ch_count[1] == 1 && ch_count[2] == 1)
		return (ft_true);
	else
		return (ft_false);
}
