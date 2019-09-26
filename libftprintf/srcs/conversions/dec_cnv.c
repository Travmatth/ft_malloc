/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_cnv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:26:53 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 16:24:30 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/conversions.h"

/*
** dec_cnv.c
** used by the format decimal conversion function to detect type, size and sign
** of variadic argument in order to correctly output it
*/

void	handle_ll(t_val type, t_fmt *fmt, const char *lookup)
{
	if (type.signed_llong < 0)
	{
		type.signed_llong *= -1;
		SET_IS_NEG(fmt->flags);
	}
	fmt->out = ft_uintmaxtoa_base(type.signed_llong, 10, lookup);
}

void	handle_hh(t_val type, t_fmt *fmt, const char *lookup)
{
	if (type.signed_short == 128 || type.signed_short == -128)
	{
		fmt->out = ft_strdup("128");
		SET_IS_NEG(fmt->flags);
	}
	else if (type.signed_char < 0)
	{
		fmt->out = ft_uintmaxtoa_base(type.signed_char *= -1, 10, lookup);
		SET_IS_NEG(fmt->flags);
	}
	else
		fmt->out = ft_uintmaxtoa_base(type.signed_char, 10, lookup);
}

void	handle_h(t_val type, t_fmt *fmt, const char *lookup)
{
	if (type.intmax < -32768)
		fmt->out = ft_uintmaxtoa_base(0, 10, lookup);
	else if (type.intmax == -32768)
		fmt->out = ft_uintmaxtoa_base(0, 10, lookup);
	else if (type.intmax == 32767)
		fmt->out = ft_uintmaxtoa_base(type.intmax, 10, lookup);
	else if (type.intmax > 32767)
	{
		SET_IS_NEG(fmt->flags);
		fmt->out = ft_uintmaxtoa_base(type.intmax, 10, lookup);
	}
	else if (type.signed_short < 0)
	{
		type.signed_short *= -1;
		SET_IS_NEG(fmt->flags);
		fmt->out = ft_uintmaxtoa_base(type.signed_short, 10, lookup);
	}
	else
		fmt->out = ft_uintmaxtoa_base(type.signed_short, 10, lookup);
}

void	handle_l(t_val type, t_fmt *fmt, const char *lookup)
{
	if (type.signed_long < 0)
	{
		type.signed_long *= -1;
		SET_IS_NEG(fmt->flags);
	}
	fmt->out = ft_uintmaxtoa_base(type.signed_long, 10, lookup);
}

void	handle_d(t_val type, t_fmt *fmt, const char *lookup)
{
	if (type.signed_int <= (int)I_MIN)
	{
		SET_IS_NEG(fmt->flags);
		fmt->out = ft_uintmaxtoa_base(type.intmax, 10, lookup);
	}
	else
	{
		if (type.signed_int > I_MAX)
			SET_IS_NEG(fmt->flags);
		else if (type.signed_int < 0)
		{
			type.signed_int *= -1;
			SET_IS_NEG(fmt->flags);
		}
		fmt->out = ft_uintmaxtoa_base(type.signed_int, 10, lookup);
	}
}
