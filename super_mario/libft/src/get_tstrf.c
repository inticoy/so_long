/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tstrf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:13:18 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/25 16:38:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	get_tstrf(const char *fmt, t_format format, va_list *args)
{
	t_string	tstr;

	if (!format.specifier)
		tstr = get_tstr((char *)fmt, format.len, format.len + 1);
	else
	{	
		tstr = ft_vtoa(format.specifier, args);
		tstr = convert_precision(tstr, format);
		tstr = convert_prefix(tstr, format);
		tstr = convert_sign(tstr, format);
		tstr = convert_space(tstr, format);
		tstr = convert_padding(tstr, format);
	}
	return (tstr);
}
