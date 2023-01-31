/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:34:02 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/25 16:38:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_format	format;
	t_string	string;
	int			written;
	int			printed;

	va_start(args, fmt);
	written = 0;
	printed = 0;
	while (*fmt)
	{
		format = get_formatf(fmt);
		string = get_tstrf(fmt, format, &args);
		if (!string.str)
			return (-1);
		written = write(1, string.str, string.len);
		if (format.specifier)
			ft_free_s(string.str);
		if (written < 0)
			return (-1);
		printed += written;
		fmt += format.len;
	}
	va_end(args);
	return (printed);
}
