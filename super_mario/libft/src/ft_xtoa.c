/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:19:06 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/25 16:38:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_xdigits(unsigned int num)
{
	if (num < 16)
		return (1);
	else
		return (get_xdigits(num / 16) + 1);
}

char	*ft_xtoa(unsigned int num)
{
	const size_t		len = get_xdigits(num);
	size_t				i;
	char				*ret;

	ret = (char *) ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (FT_NULL);
	i = 0;
	while (i < len)
	{
		ret[len - 1 - i] = "0123456789abcdef"[num % 16];
		num /= 16;
		i++;
	}
	return (ret);
}
