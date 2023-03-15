/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:38:59 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/15 16:55:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include "fcntl.h" 

t_bool	validate_map(t_map map)
{
	t_bool	validation[5];

	validation[0] = is_rectangle(map);
	validation[1] = is_surrounded(map);
	validation[2] = has_proper_char(map);
	validation[3] = is_playable(map);
	validation[4] = has_valid_route(map);
	if (!validation[0])
		ft_putstr_fd("MAP ERROR: Map is not rectangle.\n", STDERR);
	else if (!validation[1])
		ft_putstr_fd("MAP ERROR: Map is not surrounded by walls.\n", STDERR);
	else if (!validation[2])
		ft_putstr_fd("MAP ERROR: Map has improper character(s).\n", STDERR);
	else if (!validation[3])
		ft_putstr_fd("MAP ERROR: Map has improper number of characters.\n", \
					STDERR);
	else if (!validation[4])
		ft_putstr_fd("MAP ERROR: Map has no valid route.\n", STDERR);
	if (validation[0] && validation[1] && \
		validation[2] && validation[3] && validation[4])
		return (ft_true);
	else
		return (ft_false);
}
