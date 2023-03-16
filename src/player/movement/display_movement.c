/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:10:41 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 17:44:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	display_in_window(t_game g)
{
	return ;
}

static void	display_in_shell(t_game g)
{
	char	*direction;

	direction = FT_NULL;
	if (!g.player.v.x && g.player.v.y < 0)
		direction = "up";
	else if (!g.player.v.x && g.player.v.y > 0)
		direction = "down";
	else if (g.player.v.x < 0 && !g.player.v.y)
		direction = "left";
	else if (g.player.v.x > 0 && !g.player.v.y)
		direction = "right";
	ft_printf("%11d move toward %s\n", g.player.movement, direction);
}

void	display_movement(t_game g, t_bool bonus)
{
	if (!has_movement(&g))
		return ;
	if (bonus)
		display_in_window(g);
	else
		display_in_shell(g);
}
