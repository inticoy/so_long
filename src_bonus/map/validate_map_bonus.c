/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:38:59 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:47:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

t_bool	validate_map(t_map map)
{
	if (!is_rectangle(map))
		ft_putstr_fd("error: map is not rectangle.\n", STDERR);
	else if (!is_surrounded(map))
		ft_putstr_fd("error: map is not surrounded by walls.\n", STDERR);
	else if (!has_proper_char(map))
		ft_putstr_fd("error: map has improper character(s).\n", STDERR);
	else if (!is_playable(map))
		ft_putstr_fd("error: map has improper number of characters.\n", STDERR);
	else if (!has_valid_route(map))
		ft_putstr_fd("error: map has no valid route.\n", STDERR);
	else
		return (ft_true);
	return (ft_false);
}
