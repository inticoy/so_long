/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tstr_auto_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:03:43 by gyoon             #+#    #+#             */
/*   Updated: 2022/12/17 15:46:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_string	get_tstr_auto(char *str)
{
	if (!str)
		return (get_tstr(FT_NULL, -1, 0));
	else
		return (get_tstr(str, ft_strlen(str), ft_strlen(str) + 1));
}
