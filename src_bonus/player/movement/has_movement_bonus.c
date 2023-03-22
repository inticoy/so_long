/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_movement_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:22:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:47:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

t_bool	has_movement(t_game *g)
{
	if (g->player.v.x || g->player.v.y)
		return (ft_true);
	else
		return (ft_false);
}
