/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:38:06 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/31 16:16:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		raise_error("Execution must be './so_long [map PATH]'\n");
	g = init_game(argv[1]);
	mlx_hook(g.win, E_KEY_PRESS, M_KEY_PRESS, hook_key_press, &g);
	mlx_hook(g.win, E_KEY_RELEASE, M_KEY_RELEASE, hook_key_release, &g);
	mlx_loop_hook(g.mlx, hook_loop, &g);
	mlx_loop(g.mlx);
	return (0);
}
