/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:43:42 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/31 17:05:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(void)
{
	t_map	map;

	map.map = FT_NULL;
	map.size = init_point(0, 0);
	return (map);
}