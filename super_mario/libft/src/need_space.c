/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:44:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/25 16:38:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	need_space(t_string tstr, t_format format)
{
	if (!format.flag.space)
		return (ft_false);
	else if (tstr.str[0] == '+' || tstr.str[0] == '-')
		return (ft_false);
	else if (format.specifier == 'd')
		return (ft_true);
	else if (format.specifier == 'i')
		return (ft_true);
	else
		return (ft_false);
}
