/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:29:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/25 16:38:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flag	update_flag(t_flag flag, int c)
{
	if (c == '-')
		flag.left = ft_true;
	else if (c == '+')
		flag.sign = ft_true;
	else if (c == ' ')
		flag.space = ft_true;
	else if (c == '#')
		flag.prefix = ft_true;
	else if (c == '0')
		flag.zero = ft_true;
	return (flag);
}
