/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:59:55 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/25 16:38:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	need_padding(t_string tstr, t_format format)
{
	if (format.width <= tstr.len)
		return (ft_false);
	else
		return (ft_true);
}
