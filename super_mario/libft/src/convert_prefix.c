/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:53:09 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/25 16:38:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	is_all_zero(t_string tstr)
{
	t_bool	ret;
	int		i;

	ret = ft_true;
	i = 0;
	while (i < tstr.len)
	{
		if (tstr.str[i] != '0')
			ret = ft_false;
		i++;
	}
	return (ret);
}

static t_string	apply_prefix(t_string tstr, t_format format)
{
	char		*str;

	if (is_all_zero(tstr))
		return (tstr);
	str = ft_strjoin("0x", tstr.str);
	if (format.specifier == 'X')
		ft_strtoupper(str);
	ft_free_s(tstr.str);
	return (get_tstr_auto(str));
}

t_string	convert_prefix(t_string tstr, t_format format)
{
	if (!tstr.str)
		return (tstr);
	else if (!need_prefix(format))
		return (tstr);
	else
		return (apply_prefix(tstr, format));
}
