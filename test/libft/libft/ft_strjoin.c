/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:19:51 by gyoon             #+#    #+#             */
/*   Updated: 2022/09/14 23:27:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	slen1 = ft_strlen(s1);
	const size_t	slen2 = ft_strlen(s2);
	char			*ret;
	size_t			i;

	ret = (char *) malloc(sizeof(char) * (slen1 + slen2 + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < slen1)
		ret[i++] = *s1++;
	while (i < slen1 + slen2)
		ret[i++] = *s2++;
	ret[i] = 0;
	return (ret);
}
