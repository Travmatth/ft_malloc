/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:29:21 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 16:06:12 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/conversions.h"

void	to_hex(t_fmt *fmt)
{
	char	*up;

	up = fmt->cnv == 'x' ? HEX_VALUES_LOWER : HEX_VALUES_UPPER;
	if (fmt->len.modifiers[0] == 'h' && fmt->len.modifiers[1] == 'h')
		fmt->out = ft_uintmaxtoa_base(fmt->type.unsigned_char, 16, up);
	else if (fmt->len.modifiers[0] == 'l' && fmt->len.modifiers[1] == 'l')
		fmt->out = ft_uintmaxtoa_base(fmt->type.unsigned_llong, 16, up);
	else if (fmt->len.modifiers[0] == 'h')
		fmt->out = ft_uintmaxtoa_base(fmt->type.unsigned_short, 16, up);
	else if (fmt->len.modifiers[0] == 'l')
		fmt->out = ft_uintmaxtoa_base(fmt->type.unsigned_long, 16, up);
	else if (fmt->len.modifiers[0] == 'j')
		fmt->out = ft_uintmaxtoa_base(fmt->type.uintmax, 16, up);
	else if (fmt->len.modifiers[0] == 'z')
		fmt->out = ft_uintmaxtoa_base(fmt->type.sizet, 16, up);
	else if (fmt->len.modifiers[0] == 't')
		fmt->out = ft_uintmaxtoa_base(fmt->type.ptr_diff, 16, up);
	else
		fmt->out = ft_uintmaxtoa_base(fmt->type.unsigned_int, 16, up);
	fmt->len.out = LEN(fmt->out, 0);
	ftprintf_format_nbr(fmt);
}
