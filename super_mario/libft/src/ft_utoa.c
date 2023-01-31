/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:55:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/25 16:38:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_udigits(unsigned int u)
{
	if (u < 10)
		return (1);
	else
		return (get_udigits(u / 10) + 1);
}

static char	*set_utoa(char *s, unsigned int u)
{
	if (u >= 10)
		s = set_utoa(s, u / 10);
	*s++ = '0' + (u % 10);
	return (s);
}

char	*ft_utoa(unsigned int u)
{
	char	*ret;

	ret = (char *)ft_calloc(get_udigits(u) + 1, sizeof(char));
	if (!ret)
		return (FT_NULL);
	set_utoa(ret, u);
	return (ret);
}
