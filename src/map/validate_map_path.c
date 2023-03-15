/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:11:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/15 16:48:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <fcntl.h>

static t_bool	is_exist(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	close(fd);
	if (fd > 0)
		return (ft_true);
	else
		return (ft_false);
}

static t_bool	is_directory(char *map_path)
{
	int	fd;

	fd = open(map_path, O_DIRECTORY);
	close(fd);
	if (fd > 0)
		return (ft_true);
	else
		return (ft_false);
}

t_bool	validate_map_file(char *map_path)
{
	t_bool	validation[2];

	validation[0] = is_exist(map_path);
	validation[1] = !is_directory(map_path);
	if (!validation[0])
		ft_putstr_fd("PATH ERROR: Map does not exist.\n", STDERR);
	else if (!validation[1])
		ft_putstr_fd("PATH ERROR: Map must be a file, not directory.\n", \
					STDERR);
	if (validation[0] && validation[1])
		return (ft_true);
	else
		return (ft_false);
}
