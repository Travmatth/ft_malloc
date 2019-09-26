/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_dec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:25:48 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 16:06:12 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/conversions.h"

static void	handle_jztd(t_val type, t_fmt *fmt, const char *lookup)
{
	if (IS_J(fmt))
	{
		if (type.intmax < 0)
		{
			type.intmax *= -1;
			SET_IS_NEG(fmt->flags);
		}
		fmt->out = ft_uintmaxtoa_base(type.intmax, 10, lookup);
	}
	else if (IS_Z(fmt))
	{
		fmt->out = ft_uintmaxtoa_base(type.sizet, 10, lookup);
	}
	else if (IS_T(fmt))
	{
		if (type.ptr_diff < 0)
		{
			type.ptr_diff *= -1;
			SET_IS_NEG(fmt->flags);
		}
		fmt->out = ft_uintmaxtoa_base(type.ptr_diff, 10, lookup);
	}
	else
		handle_d(type, fmt, lookup);
}

void		to_dec(t_fmt *fmt)
{
	char	*lookup;
	t_val	type;

	type = fmt->type;
	lookup = "0123456789";
	if (IS_HH(fmt))
		handle_hh(type, fmt, lookup);
	else if (IS_LL(fmt))
		handle_ll(type, fmt, lookup);
	else if (IS_H(fmt))
		handle_h(type, fmt, lookup);
	else if (IS_L(fmt))
		handle_l(type, fmt, lookup);
	else if (fmt->cnv == 'D')
		fmt->out = ft_uintmaxtoa_base(type.intmax, 10, lookup);
	else
		handle_jztd(type, fmt, lookup);
	if (GET(fmt->flags, '+') && !GET(fmt->flags, ' ') && fmt->width == I_MIN
		&& fmt->out && *fmt->out == '0' && !fmt->out[1] && (fmt->len.out += 1))
		if (fmt->precision == 0 && !GET(fmt->flags, '#'))
			fmt->len.out = 0;
	ftprintf_format_nbr(fmt);
}
