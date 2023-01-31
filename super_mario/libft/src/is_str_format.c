/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:06:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/01/25 16:38:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	is_str_format(t_format format)
{
	const char	c = format.specifier;

	if (c == 's')
		return (ft_true);
	else
		return (ft_false);
}
