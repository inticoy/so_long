/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:26:42 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/16 15:39:53 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

t_key	init_key(void)
{
	t_key	k;

	k.w = ft_false;
	k.a = ft_false;
	k.s = ft_false;
	k.d = ft_false;
	k.r = ft_false;
	k.shift = ft_false;
	k.esc = ft_false;
	return (k);
}
