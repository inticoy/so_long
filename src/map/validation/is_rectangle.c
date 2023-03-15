/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:55:18 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/15 17:00:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

t_bool	is_rectangle(t_map map)
{
	while (*map.map)
	{
		if (map.size.x != ft_strlen(*map.map) - 1)
			return (ft_false);
		map.map++;
	}
	return (ft_true);
}
