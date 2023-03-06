/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:54:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/06 18:57:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_blocks(void *mlx, t_assets *assets)
{
	assets->block[0] = read_image(mlx, "./assets/block/sky_0.xpm");
	assets->block[1] = read_image(mlx, "./assets/block/ground_0.xpm");
	assets->block[2] = read_image(mlx, "./assets/block/stair_0.xpm");
	assets->block[3] = read_image(mlx, "./assets/block/wall_0.xpm");
	assets->block[10] = read_image(mlx, "./assets/item/item_0.xpm");
	assets->block[11] = read_image(mlx, "./assets/item/item_1.xpm");
	assets->block[12] = read_image(mlx, "./assets/item/item_2.xpm");
	assets->block[13] = read_image(mlx, "./assets/item/item_3.xpm");
}

static void	read_marios(void *mlx, t_assets *assets)
{
	assets->mario[0][0] = read_image(mlx, "./assets/mario/left/mario_6.xpm");
	assets->mario[0][1] = read_image(mlx, "./assets/mario/left/mario_7.xpm");
	assets->mario[0][2] = read_image(mlx, "./assets/mario/left/mario_8.xpm");
	assets->mario[0][3] = read_image(mlx, "./assets/mario/left/mario_9.xpm");
	assets->mario[0][4] = read_image(mlx, "./assets/mario/left/mario_10.xpm");
	assets->mario[0][5] = read_image(mlx, "./assets/mario/left/mario_11.xpm");
	assets->mario[1][0] = read_image(mlx, "./assets/mario/right/mario_0.xpm");
	assets->mario[1][1] = read_image(mlx, "./assets/mario/right/mario_1.xpm");
	assets->mario[1][2] = read_image(mlx, "./assets/mario/right/mario_2.xpm");
	assets->mario[1][3] = read_image(mlx, "./assets/mario/right/mario_3.xpm");
	assets->mario[1][4] = read_image(mlx, "./assets/mario/right/mario_4.xpm");
	assets->mario[1][5] = read_image(mlx, "./assets/mario/right/mario_5.xpm");
	assets->mario[2][0] = read_image(mlx, "./assets/mario/mario_dead.xpm");
	assets->mario[2][1] = read_image(mlx, "./assets/mario/mario_dead.xpm");
	assets->mario[2][2] = read_image(mlx, "./assets/mario/mario_dead.xpm");
	assets->mario[2][3] = read_image(mlx, "./assets/mario/mario_dead.xpm");
	assets->mario[2][4] = read_image(mlx, "./assets/mario/mario_dead.xpm");
	assets->mario[2][5] = read_image(mlx, "./assets/mario/mario_dead.xpm");
}

static void	read_coins(void *mlx, t_assets *assets)
{
	assets->coin[0] = read_image(mlx, "./assets/coin/coin_0.xpm");
	assets->coin[1] = read_image(mlx, "./assets/coin/coin_1.xpm");
	assets->coin[2] = read_image(mlx, "./assets/coin/coin_2.xpm");
	assets->coin[3] = read_image(mlx, "./assets/coin/coin_3.xpm");
	assets->coin[4] = read_image(mlx, "./assets/coin/coin.xpm");
}

static void	read_goombas(void *mlx, t_assets *assets)
{
	assets->goomba[0] = read_image(mlx, "./assets/goomba/goomba_right.xpm");
	assets->goomba[1] = read_image(mlx, "./assets/goomba/goomba_left.xpm");
	assets->goomba[2] = read_image(mlx, "./assets/goomba/goomba_dead.xpm");
}

t_assets	read_assets(void *mlx)
{
	t_assets	assets;

	read_blocks(mlx, &assets);
	read_marios(mlx, &assets);
	read_coins(mlx, &assets);
	read_goombas(mlx, &assets);
	assets.peach[0] = read_image(mlx, "./assets/peach/peach.xpm");
	return (assets);
}
