/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 14:39:29 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 16:26:39 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/conversions.h"

/*
** format_nbr.c
** used by ftprintf_format_nbr to correctly format string for outputting
*/

size_t	fmt_str_unchanged(t_fmt *fmt, size_t orig_len)
{
	fmt->out = fmt->type.str;
	fmt->len.out = orig_len;
	return (fmt->len.out);
}

size_t	set_alternate(t_fmt *fmt)
{
	ft_memcpy(fmt->prefix, (void*)"0", 1);
	if (fmt->cnv == 'o')
		return (1);
	ft_memcpy((void*)(fmt->prefix + 1), (void*)"x", fmt->cnv == 'x' ? 1 : 0);
	ft_memcpy((void*)(fmt->prefix + 1), (void*)"X", fmt->cnv == 'X' ? 1 : 0);
	return (2);
}

size_t	get_prefix(t_fmt *fmt)
{
	if (!(ft_strchr("xXodip", fmt->cnv))
		|| (ft_strchr("xXo", fmt->cnv) && IS_ZERO(fmt)))
		return (0);
	if (GET(fmt->flags, ' '))
		ft_memcpy(fmt->prefix, (void*)" ", 1);
	if (GET(fmt->flags, '+'))
		ft_memcpy(fmt->prefix, (void*)"+", 1);
	if ((fmt->cnv == 'd' || fmt->cnv == 'i') && GET_IS_NEG(fmt->flags))
		ft_memcpy(fmt->prefix, (void*)"-", 1);
	if (fmt->cnv == 'p')
	{
		ft_memcpy(fmt->prefix, (void*)"0", 1);
		if (GET(fmt->flags, '#'))
			ft_memcpy((void*)(fmt->prefix + 1), (void*)"X", 1);
		else
			ft_memcpy((void*)(fmt->prefix + 1), (void*)"x", 1);
		return (2);
	}
	else if (GET(fmt->flags, '#'))
		return (set_alternate(fmt));
	return (*fmt->prefix ? 1 : 0);
}

void	set_zero_padding(t_fmt *fmt
						, size_t *zero_len
						, size_t *width_len
						, size_t *prefix_len)
{
	if (GET(fmt->flags, '-'))
		*width_len -= *prefix_len;
	else if (*zero_len >= fmt->len.out + *prefix_len)
		*zero_len -= *prefix_len;
	else if (*zero_len && (*fmt->prefix == '+' || *fmt->prefix == '-'))
		*zero_len -= 1;
	else if (*width_len && (*fmt->prefix == '+' || *fmt->prefix == '-'))
		*width_len -= 1;
	return ;
}

void	set_prefix(t_fmt *fmt
				, size_t *zero_len
				, size_t *width_len
				, size_t *prefix_len)
{
	if (!(*prefix_len = get_prefix(fmt)))
		return ;
	if (!GET(fmt->flags, '-') && !GET(fmt->flags, '0'))
	{
		if (*width_len >= *prefix_len)
			*width_len -= *prefix_len;
		return ;
	}
	if (GET(fmt->flags, '0') &&
		(fmt->precision == I_MIN || *zero_len > fmt->precision + *prefix_len))
		set_zero_padding(fmt, zero_len, width_len, prefix_len);
	if (GET(fmt->flags, '0') &&
		(fmt->cnv == 'd' || fmt->cnv == 'i') && GET_IS_NEG(fmt->flags))
	{
		if (!GET(fmt->flags, '-'))
			*zero_len -= *prefix_len;
	}
	if ((GET(fmt->flags, '-')) && !GET(fmt->flags, '0'))
	{
		if (*width_len > *prefix_len)
			*width_len -= *prefix_len;
		return ;
	}
}
