/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_movement_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:10:41 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:52:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"
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
	ft_printf("%11d th move\n", g.player.movement);
}

void	display_movement(t_game g, t_bool bonus)
{
	if (bonus)
		display_in_window(g);
	else if (has_movement(&g))
		display_in_shell(g);
}
