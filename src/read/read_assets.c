/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:54:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/08 16:20:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_blocks(void *mlx, t_assets *assets)
{
	assets->block[0] = read_image(mlx, "./assets/block/sky.xpm");
	assets->block[1] = read_image(mlx, "./assets/block/ground.xpm");
	assets->block[2] = read_image(mlx, "./assets/block/stair.xpm");
	assets->block[3] = read_image(mlx, "./assets/block/wall.xpm");
	assets->block[10] = read_image(mlx, "./assets/block/item/0.xpm");
	assets->block[11] = read_image(mlx, "./assets/block/item/1.xpm");
	assets->block[12] = read_image(mlx, "./assets/block/item/2.xpm");
	assets->block[13] = read_image(mlx, "./assets/block/item/3.xpm");
}

static void	read_characters(void *mlx, t_assets *assets)
{
	assets->player[0][0] = read_image(mlx, "./assets/mario/left/stand.xpm");
	assets->player[0][1] = read_image(mlx, "./assets/mario/left/walk_0.xpm");
	assets->player[0][2] = read_image(mlx, "./assets/mario/left/walk_1.xpm");
	assets->player[0][3] = read_image(mlx, "./assets/mario/left/walk_2.xpm");
	assets->player[0][4] = read_image(mlx, "./assets/mario/left/slide.xpm");
	assets->player[0][5] = read_image(mlx, "./assets/mario/left/jump.xpm");
	assets->player[1][0] = read_image(mlx, "./assets/mario/right/stand.xpm");
	assets->player[1][1] = read_image(mlx, "./assets/mario/right/walk_0.xpm");
	assets->player[1][2] = read_image(mlx, "./assets/mario/right/walk_1.xpm");
	assets->player[1][3] = read_image(mlx, "./assets/mario/right/walk_2.xpm");
	assets->player[1][4] = read_image(mlx, "./assets/mario/right/slide.xpm");
	assets->player[1][5] = read_image(mlx, "./assets/mario/right/jump.xpm");
	assets->player[2][0] = read_image(mlx, "./assets/mario/dead/dead.xpm");
	assets->player[2][1] = read_image(mlx, "./assets/mario/dead/dead.xpm");
	assets->player[2][2] = read_image(mlx, "./assets/mario/dead/dead.xpm");
	assets->player[2][3] = read_image(mlx, "./assets/mario/dead/dead.xpm");
	assets->player[2][4] = read_image(mlx, "./assets/mario/dead/dead.xpm");
	assets->player[2][5] = read_image(mlx, "./assets/mario/dead/dead.xpm");
	assets->enemy[0] = read_image(mlx, "./assets/goomba/walk_0.xpm");
	assets->enemy[1] = read_image(mlx, "./assets/goomba/walk_1.xpm");
	assets->enemy[2] = read_image(mlx, "./assets/goomba/dead.xpm");
	assets->exit = read_image(mlx, "./assets/peach/stand.xpm");
}

static void	read_collectibles(void *mlx, t_assets *assets)
{
	assets->collectible[0] = read_image(mlx, "./assets/coin/0.xpm");
	assets->collectible[1] = read_image(mlx, "./assets/coin/1.xpm");
	assets->collectible[2] = read_image(mlx, "./assets/coin/2.xpm");
}

t_assets	read_assets(void *mlx)
{
	t_assets	assets;

	read_blocks(mlx, &assets);
	read_characters(mlx, &assets);
	read_collectibles(mlx, &assets);
	return (assets);
}
