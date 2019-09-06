/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:30:44 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 16:06:12 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/conversions.h"

void	to_ptr(t_fmt *fmt)
{
	char		*lookup;

	lookup = GET(fmt->flags, '#') ? HEX_VALUES_UPPER : HEX_VALUES_LOWER;
	if (!(fmt->out = ft_uintmaxtoa_base(fmt->type.unsigned_llong, 16, lookup)))
		exit(1);
	ftprintf_format_nbr(fmt);
}
