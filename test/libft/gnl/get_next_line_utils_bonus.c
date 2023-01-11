/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:06:49 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/02 23:07:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	get_index(char *s, char c, int begin, int end)
{
	int	i;

	i = begin;
	while (i < end)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (end - 1);
}

static void	*memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((char *) dst)[i] = ((const char *) src)[i];
		i++;
	}
	return (dst);
}

int	update_line(t_gnl_string *l, t_buffer b)
{
	t_gnl_string	tmp;

	tmp.len = get_index(b.buf, '\n', b.idx, b.len) - b.idx + 1 + l->len;
	if (l->len && tmp.len < l->size)
		memcpy(l->str + l->len, b.buf + b.idx, tmp.len - l->len);
	else
	{
		l->size = tmp.len * 10 + 1;
		tmp.str = (char *) malloc(sizeof(char) * (l->size));
		if (!tmp.str)
		{
			if (l->str)
				free(l->str);
			l->str = 0;
			return (0);
		}
		memcpy(tmp.str, l->str, l->len);
		memcpy(tmp.str + l->len, b.buf + b.idx, tmp.len - l->len);
		if (l->str)
			free(l->str);
		l->str = tmp.str;
	}
	l->len = tmp.len;
	l->str[l->len] = 0;
	return (1);
}

int	update_buffer(t_buffer *b)
{
	b->idx = (get_index(b->buf, '\n', b->idx, b->len) + 1) % b->len;
	return (1);
}

t_gnl_string	optimize_string(t_gnl_string s)
{
	t_gnl_string	opt;

	opt.str = 0;
	opt.len = s.len;
	opt.size = s.len + 1;
	if (!s.str || s.len + 1 == s.size)
		return (s);
	else
	{
		opt.str = (char *) malloc(sizeof(char) * opt.size);
		if (!opt.str)
		{
			free(s.str);
			return (opt);
		}
		memcpy(opt.str, s.str, opt.len);
		opt.str[opt.len] = 0;
		free(s.str);
		return (opt);
	}
}
