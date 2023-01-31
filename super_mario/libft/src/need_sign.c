/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_sign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:42:43 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/25 16:38:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	need_sign(t_format format)
{
	if (!format.flag.sign)
		return (ft_false);
	else if (format.specifier == 'd')
		return (ft_true);
	else if (format.specifier == 'i')
		return (ft_true);
	else
		return (ft_false);
}
