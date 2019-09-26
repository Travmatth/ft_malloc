/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_oct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:29:58 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 16:06:12 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/conversions.h"

static void	assign_oct(t_fmt *fmt)
{
	if (fmt->len.modifiers[0] == 'h' && fmt->len.modifiers[1] == 'h')
		fmt->out = ft_uintmaxtoa_base(fmt->type.unsigned_char, 8, "01234567");
	else if (fmt->len.modifiers[0] == 'l' && fmt->len.modifiers[1] == 'l')
		fmt->out = ft_uintmaxtoa_base(fmt->type.unsigned_llong, 8, "01234567");
	else if (fmt->len.modifiers[0] == 'h')
		fmt->out = ft_uintmaxtoa_base(fmt->type.unsigned_short, 8, "01234567");
	else if (fmt->len.modifiers[0] == 'l')
		fmt->out = ft_uintmaxtoa_base(fmt->type.unsigned_long, 8, "01234567");
	else if (fmt->len.modifiers[0] == 'j')
		fmt->out = ft_uintmaxtoa_base(fmt->type.uintmax, 8, "01234567");
	else if (fmt->len.modifiers[0] == 'z')
		fmt->out = ft_uintmaxtoa_base(fmt->type.sizet, 8, "01234567");
	else if (fmt->len.modifiers[0] == 't')
		fmt->out = ft_uintmaxtoa_base(fmt->type.ptr_diff, 8, "01234567");
	else
		fmt->out = ft_uintmaxtoa_base(fmt->type.unsigned_int, 8, "01234567");
}

void		to_oct(t_fmt *fmt)
{
	assign_oct(fmt);
	fmt->len.out = LEN(fmt->out, 0);
	if (fmt->len.out == 1 && *fmt->out == '0')
	{
		if (fmt->precision == 0 && !GET(fmt->flags, '#'))
		{
			ft_strdel(&fmt->out);
			fmt->out = ft_strdup("");
			fmt->len.out = 0;
		}
		else
			return ;
	}
	ftprintf_format_nbr(fmt);
}
