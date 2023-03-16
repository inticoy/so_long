/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_release.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:30:43 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 15:40:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	hook_key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->key.w = ft_false;
	else if (keycode == KEY_A)
		game->key.a = ft_false;
	else if (keycode == KEY_S)
		game->key.s = ft_false;
	else if (keycode == KEY_D)
		game->key.d = ft_false;
	else if (keycode == KEY_R)
		game->key.r = ft_false;
	else if (keycode == KEY_SHIFT)
		game->key.shift = ft_false;
	else if (keycode == KEY_ESC)
		game->key.esc = ft_false;
	ft_printf("released : %d\n", keycode);
	return (0);
}
