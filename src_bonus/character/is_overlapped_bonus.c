/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_overlapped_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:16:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:47:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

t_bool	is_overlapped(t_point pos1, t_point pos2)
{
	int	dx;
	int	dy;

	if (pos1.x > pos2.x)
		dx = pos1.x - pos2.x;
	else
		dx = pos2.x - pos1.x;
	if (pos1.y > pos2.y)
		dy = pos1.y - pos2.y;
	else
		dy = pos2.y - pos1.y;
	if (dx < CHAR_X && dy < CHAR_Y)
		return (ft_true);
	else
		return (ft_false);
}
