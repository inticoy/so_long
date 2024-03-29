/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:11:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/22 17:05:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
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

t_bool	validate_map_path(char *map_path)
{
	if (!is_exist(map_path))
		ft_putstr_fd("error: map does not exist.\n", STDERR);
	else if (is_directory(map_path))
		ft_putstr_fd("error: map must be a file, not directory.\n", STDERR);
	else
		return (ft_true);
	return (ft_false);
}
