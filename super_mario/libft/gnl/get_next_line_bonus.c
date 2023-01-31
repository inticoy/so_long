/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:44 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/02 23:08:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_gnl_string	init_string(void)
{
	t_gnl_string	s;

	s.str = 0;
	s.len = 0;
	s.size = 0;
	return (s);
}

static int	read_buffer(int fd, t_buffer *b)
{
	b->len = read(fd, b->buf, BUFFER_SIZE);
	if (b->len > 0)
		return (1);
	else
		return (0);
}

static t_buffer	*get_buffer(int fd, t_buffer *b)
{
	while (1)
	{
		if (b->fd == fd)
			return (b);
		else if (b->next)
			b = b->next;
		else
		{
			b->next = (t_buffer *) malloc(sizeof(t_buffer));
			if (!b->next)
				return (0);
			b = b->next;
			b->fd = fd;
			b->idx = 0;
			b->len = 0;
			b->next = 0;
		}
	}
}

static int	delete_buffer(int fd, t_buffer *b)
{
	t_buffer	*curr;
	t_buffer	*temp;

	curr = b;
	while (curr->next)
	{
		if (curr->next->fd == fd)
		{
			temp = curr->next->next;
			free(curr->next);
			curr->next = temp;
			return (1);
		}
		else
			curr = curr->next;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_buffer		head;
	t_buffer			*curr;
	t_gnl_string		line;

	curr = get_buffer(fd, &head);
	if (!curr)
		return (0);
	line = init_string();
	while (curr)
	{
		if (!curr->idx && !read_buffer(fd, curr))
			break ;
		if (!update_line(&line, *curr) || !update_buffer(curr))
			break ;
		if (line.str[line.len - 1] == '\n' || curr->idx)
			break ;
	}
	line = optimize_string(line);
	if ((curr->len < BUFFER_SIZE && !curr->idx) || !line.str)
		delete_buffer(fd, &head);
	return (line.str);
}
