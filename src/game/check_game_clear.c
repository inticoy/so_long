/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:55:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/08 16:05:58 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

t_bool	check_game_clear(t_game *g)
{
	if (get_remaining_collectibles(g))
		return (ft_false);
	else if (!is_overlapped(g->player.pos, g->exit.pos))
		return (ft_false);
	else
		return (ft_true);
}
