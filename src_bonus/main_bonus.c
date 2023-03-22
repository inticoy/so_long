/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:38:06 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 23:04:56 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		raise_error("usage: ./so_long [map PATH]\n");
	g = init_game(argv[1]);
	mlx_hook(g.win, E_KEY_PRESS, M_KEY_PRESS, hook_key_press, &g);
	mlx_hook(g.win, E_KEY_RELEASE, M_KEY_RELEASE, hook_key_release, &g);
	mlx_loop_hook(g.mlx, run_game, &g);
	mlx_loop(g.mlx);
	return (0);
}
