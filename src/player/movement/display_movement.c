/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:10:41 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 20:16:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include "mlx.h"

static void	display_in_window(t_game g)
{
	char	*movement;

	movement = ft_itoa(g.player.movement);
	mlx_string_put(g.mlx, g.win, 0, 32, 0xFFFFFFFF, movement);
	ft_free_s(movement);
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
	else if (g.player.v.x < 0 && g.player.v.y < 0)
		direction = "up-left";
	else if (g.player.v.x > 0 && g.player.v.y < 0)
		direction = "up-right";
	else if (g.player.v.x < 0 && g.player.v.y > 0)
		direction = "down-left";
	else if (g.player.v.x > 0 && g.player.v.y > 0)
		direction = "down-right";
	ft_printf("%11d move %s\n", g.player.movement, direction);
}

void	display_movement(t_game g, t_bool bonus)
{
	if (bonus)
		display_in_window(g);
	else if (has_movement(&g))
		display_in_shell(g);
}
