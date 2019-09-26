/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:49:09 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/26 15:39:35 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/internal.h"

/*
** parse.c
** a recursive descent parser to parse formatting strings into a linked list
** according to the printf formatting string syntax
** %[parameter][flags][width][.precision][length]type
*/

/*
** detect positional parameters, i.e. %3$
*/

int				valid_param(char *fmt)
{
	while (ft_isdigit(*fmt))
	{
		if (*fmt++ == '$')
			return (1);
	}
	return (0);
}

/*
** parse length modifiers
*/

static int		parse_len(t_fmt *spec
						, char **fmt
						, va_list ap
						, unsigned int depth)
{
	if (**fmt == '%')
	{
		spec->cnv = '%';
		*fmt += 1;
		return (1);
	}
	else if (!*fmt)
		return (-1);
	spec->len.modifiers[0] = ft_strchr("hljztL", **fmt) ? **fmt : 0;
	*fmt += spec->len.modifiers[0] ? 1 : 0;
	spec->len.modifiers[1] = ft_strchr("hl", **fmt) ? **fmt : 0;
	*fmt += spec->len.modifiers[1] ? 1 : 0;
	if (!*fmt || !ft_strchr(SPECIFIERS, **fmt) || !parse_cnv(spec, fmt, ap))
		return (0);
	if ((**fmt == 's') && IS_L(spec))
		spec->cnv = 'S';
	else if ((**fmt == 'c') && IS_L(spec))
		spec->cnv = 'C';
	else if ((**fmt == 'd') && IS_L(spec))
		spec->cnv = 'D';
	else
		spec->cnv = **fmt;
	spec->arg_position = depth;
	*fmt += 1;
	return (1);
}

/*
** parse width and precision
*/

static void		parse_nbr(unsigned *measurement, char **fmt, va_list ap)
{
	if (!*fmt)
		return ;
	if (**fmt == '*')
	{
		*measurement = va_arg(ap, int);
		*fmt += 1;
	}
	else if (ft_isdigit(**fmt))
	{
		*measurement = ft_atoi(*fmt);
		*fmt += *measurement == 0 ? 1 : ft_count_digits(*measurement);
	}
}

/*
** parse format specifier
*/

static int		parse_spec(t_state *state
							, char *fmt
							, va_list ap
							, unsigned int depth)
{
	t_fmt	*spec;

	if (!(spec = make_spec(state)))
		return (-1);
	if (ft_isdigit(*(++fmt)) && valid_param(fmt))
	{
		SET_IS_LINK(spec->flags);
		spec->link = ft_atoi(fmt);
		fmt += ft_count_digits(spec->link) + 1;
	}
	while (*fmt && ft_strchr("-+ 0#", *fmt))
	{
		SET(spec->flags, *fmt);
		fmt += 1;
	}
	parse_nbr(&spec->width, &fmt, ap);
	if (*fmt == '.')
	{
		fmt += 1;
		spec->precision = 0;
		parse_nbr(&spec->precision, &fmt, ap);
	}
	return (parse_len(spec, &fmt, ap, depth)
		? parse(state, fmt, ap, depth + 1)
		: -1);
}

/*
** parse formatting strings
*/

int				parse(t_state *state
						, char *fmt
						, va_list ap
						, unsigned int depth)
{
	t_fmt	*spec;
	char	*first;

	if (!*fmt)
		return (1);
	if (*fmt != '%')
	{
		if (!(spec = make_spec(state)))
			return (-1);
		first = ft_strchr(fmt, '%');
		spec->len.out = first ? first - fmt : ft_strlen(fmt);
		spec->out = ft_strsub(fmt, 0, spec->len.out);
		SET_IS_TEXT(spec->flags);
		return (parse(state, first ? first : fmt + spec->len.out, ap, depth));
	}
	return (parse_spec(state, fmt, ap, depth));
}
