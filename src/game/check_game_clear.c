/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:55:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 15:32:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

t_bool	check_game_clear(t_game *g)
{
	if (get_remaining_collectibles(g))
		return (ft_false);
	else if (!is_overlapped(g->player.pos, g->exit.pos))
		return (ft_false);
	else
		return (ft_true);
}
