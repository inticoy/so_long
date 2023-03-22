/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:07:42 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 22:47:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "mlx.h"

t_image	read_image(void *mlx, char *path)
{
	t_image	img;
	int		x;
	int		y;

	img.img = mlx_xpm_file_to_image(mlx, path, &x, &y);
	img.size = init_point(x, y);
	return (img);
}
