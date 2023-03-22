/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:22:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 15:30:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

t_bool	has_movement(t_game *g)
{
	if (g->player.v.x || g->player.v.y)
		return (ft_true);
	else
		return (ft_false);
}
