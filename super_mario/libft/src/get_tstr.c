/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:30:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/25 16:38:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	get_tstr(char *str, int len, int size)
{
	t_string	tstr;

	if (!str)
	{
		tstr.str = str;
		tstr.len = -1;
		tstr.size = 0;
	}
	else
	{
		tstr.str = str;
		tstr.len = len;
		tstr.size = size;
	}
	return (tstr);
}
