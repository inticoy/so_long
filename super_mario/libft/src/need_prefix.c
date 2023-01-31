/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_prefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:41:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/25 16:38:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	need_prefix(t_format format)
{
	if (!format.flag.prefix)
		return (ft_false);
	else if (format.specifier == 'x')
		return (ft_true);
	else if (format.specifier == 'X')
		return (ft_true);
	else
		return (ft_false);
}
