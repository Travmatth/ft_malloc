/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:36:17 by tmatthew          #+#    #+#             */
/*   Updated: 2018/11/05 15:41:27 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/conversions.h"

/*
** ftprintf_format_chr
** format given character with indicated width & precision
*/

void	ftprintf_format_chr(t_fmt *fmt)
{
	size_t	len;
	size_t	pad_len;
	char	*write_position;
	char	*pad_position;
	char	*tmp;

	len = fmt->len.out > 0 && fmt->precision != I_MIN
			&& fmt->len.out > 1 ? fmt->precision : fmt->len.out;
	pad_len = (fmt->width != I_MIN && fmt->width > 0) ? fmt->width - len : 0;
	if (fmt->len.out == len + pad_len)
		return ;
	if (!(tmp = ft_strnew(pad_len + len)))
		exit(1);
	write_position = tmp + pad_len;
	pad_position = tmp;
	if (GET(fmt->flags, '-'))
	{
		write_position = tmp;
		pad_position = tmp + len;
	}
	ft_czero(pad_position, ' ', pad_len);
	ft_memcpy(write_position, fmt->out, len);
	ft_strdel(&(fmt->out));
	fmt->len.out = len + pad_len;
	fmt->out = tmp;
}

/*
** ftprintf_format_str
** formats a given string with indicated width & precision
*/

size_t	ftprintf_format_str(t_fmt *fmt)
{
	size_t	size[3];
	char	*write_position;
	char	*pad_position;
	char	*tmp;

	size[0] = LEN(fmt->type.str, 0);
	size[1] = size[0] > 0 && fmt->precision != I_MIN
		&& fmt->precision > 0 ? fmt->precision : size[0];
	size[1] = fmt->precision == I_MIN ? 0 : size[1];
	size[2] = (fmt->width != I_MIN && fmt->width > 0)
		? fmt->width - size[1] : 0;
	if (!(size[1] + size[2]) || !(tmp = ft_strnew(size[2] + size[0])))
		return (fmt_str_unchanged(fmt, size[0]));
	write_position = tmp + size[0];
	pad_position = tmp;
	if (GET(fmt->flags, '-'))
	{
		write_position = tmp;
		pad_position = tmp + size[0];
	}
	ft_czero(pad_position, ' ', size[2]);
	ft_memcpy(write_position, fmt->type.str, size[0]);
	ft_strdel(&(fmt->type.str));
	fmt->out = tmp;
	return ((fmt->len.out = size[0] + size[2]));
}

void	write_number_left(t_fmt *fmt
						, size_t zero_len
						, size_t width_len
						, size_t prefix_len)
{
	size_t	offset;
	char	*tmp;

	offset = 0;
	if (!(tmp = ft_strnew(fmt->len.out + prefix_len + width_len + zero_len)))
		exit(1);
	ft_memcpy(tmp, fmt->prefix, prefix_len);
	offset += prefix_len;
	ft_czero(tmp + offset, '0', zero_len);
	offset += zero_len;
	ft_memcpy(tmp + offset, fmt->out, fmt->len.out);
	offset += fmt->len.out;
	ft_czero((void*)(tmp + offset), ' ', width_len);
	offset += width_len;
	ft_strdel(&fmt->out);
	fmt->len.out = offset;
	fmt->out = tmp;
}

void	write_number_right(t_fmt *fmt
							, size_t zero_len
							, size_t width_len
							, size_t prefix_len)
{
	size_t	offset;
	char	*tmp;

	offset = 0;
	if (!(tmp = ft_strnew(fmt->len.out + prefix_len + width_len + zero_len)))
		exit(1);
	if (!GET(fmt->flags, '0'))
	{
		ft_czero(tmp, ' ', width_len);
		offset += width_len;
		ft_memcpy(tmp + offset, fmt->prefix, prefix_len);
	}
	else
	{
		ft_memcpy(tmp + offset, fmt->prefix, prefix_len);
		offset += prefix_len;
		ft_czero(tmp + offset, IS_PLUSMINUS(fmt) || ft_strchr("xXbu", fmt->cnv)
			? '0' : ' ', width_len);
	}
	offset += !GET(fmt->flags, '0') ? prefix_len : width_len;
	ft_czero(tmp + offset, '0', zero_len);
	ft_memcpy(tmp + (offset += zero_len), fmt->out, fmt->len.out);
	fmt->len.out += offset;
	ft_strdel(&fmt->out);
	fmt->out = tmp;
}

/*
** Zero pad if precision > number len, or if
** right justified and 0 flag set and length too short
** Pads width if width is set and greater than existing string
** writes string
*/

void	ftprintf_format_nbr(t_fmt *fmt)
{
	size_t	zero_len;
	size_t	width_len;
	size_t	prefix_len;

	if (fmt->precision == 0 && fmt->len.out == 1 && *fmt->out == '0')
		fmt->out = ft_strdup("");
	if (!(fmt->len.out = LEN(fmt->out, 0)) && fmt->width == I_MIN)
		return ;
	zero_len = fmt->precision != I_MIN && fmt->precision > fmt->len.out
		? fmt->precision - fmt->len.out : 0;
	if (!GET(fmt->flags, '-') && GET(fmt->flags, '0') && fmt->width != I_MIN
		&& fmt->precision == I_MIN && fmt->width > fmt->len.out + zero_len
		&& !(fmt->len.out == 1))
		zero_len += (fmt->width < fmt->precision
			? fmt->width : fmt->precision) - fmt->len.out;
	width_len = fmt->width != I_MIN && fmt->width > fmt->len.out + zero_len
		? fmt->width - (fmt->len.out + zero_len) : 0;
	set_prefix(fmt, &zero_len, &width_len, &prefix_len);
	if (!(zero_len || width_len || prefix_len))
		return ;
	if (GET(fmt->flags, '-'))
		write_number_left(fmt, zero_len, width_len, prefix_len);
	else
		write_number_right(fmt, zero_len, width_len, prefix_len);
}
