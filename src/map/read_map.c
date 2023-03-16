/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:26:13 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 13:36:24 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <fcntl.h>

static int	get_num_line(char *path)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	ret = 0;
	while (ft_true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else
		{
			ret++;
			ft_free_s(line);
		}
	}
	close(fd);
	return (ret);
}

t_map	read_map(char *map_path)
{
	int		fd;
	int		i;
	char	*line;
	t_map	map;

	map = init_map();
	map.size.y = get_num_line(map_path);
	map.map = (char **)ft_calloc(map.size.y + 1, sizeof(char *));
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (map);
	i = 0;
	while (i < map.size.y)
		map.map[i++] = get_next_line(fd);
	map.size.x = ft_strlen(map.map[0]) - 1;
	close (fd);
	return (map);
}
