/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cnv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:05:52 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/25 15:28:05 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/internal.h"

/*
** parse_cnv.c
** parse variadic args according formatting string conversion specifiers
*/

/*
** parse when no len is given
** length	di	uoxX			fFeEgGaA	c	s		p		n
** (none)	int	unsigned int	double		int	char*	void*	int*
*/

void			handle_n(t_fmt *spec, va_list ap)
{
	if (IS_HH(spec))
		spec->type.void_ptr = va_arg(ap, int*);
	else if (IS_H(spec))
		spec->type.void_ptr = va_arg(ap, int*);
	else if (IS_L(spec))
		spec->type.void_ptr = va_arg(ap, long int*);
	else if (IS_LL(spec))
		spec->type.void_ptr = va_arg(ap, long long int*);
	else if (IS_J(spec))
		spec->type.void_ptr = va_arg(ap, intmax_t*);
	else if (IS_Z(spec))
		spec->type.void_ptr = va_arg(ap, size_t*);
	else if (IS_T(spec))
		spec->type.void_ptr = va_arg(ap, ptrdiff_t*);
	else
		spec->type.void_ptr = va_arg(ap, intmax_t*);
}

void			handle_di(t_fmt *spec, va_list ap)
{
	if (spec->cnv == 'D')
		spec->type.intmax = va_arg(ap, intmax_t);
	else if (IS_HH(spec))
		spec->type.signed_int = va_arg(ap, int);
	else if (IS_H(spec))
		spec->type.unsigned_short = va_arg(ap, int);
	else if (IS_L(spec))
		spec->type.signed_long = va_arg(ap, long int);
	else if (IS_LL(spec))
		spec->type.signed_llong = va_arg(ap, long long int);
	else if (IS_J(spec))
		spec->type.intmax = va_arg(ap, intmax_t);
	else if (IS_Z(spec))
		spec->type.sizet = va_arg(ap, size_t);
	else if (IS_T(spec))
		spec->type.ptr_diff = va_arg(ap, ptrdiff_t);
	else
		spec->type.signed_int = va_arg(ap, intmax_t);
}

void			handle_uox(t_fmt *spec, va_list ap)
{
	if (IS_HH(spec))
		spec->type.unsigned_int = va_arg(ap, unsigned);
	else if (IS_H(spec))
		spec->type.unsigned_short = va_arg(ap, unsigned);
	else if (IS_L(spec))
		spec->type.unsigned_long = va_arg(ap, unsigned long int);
	else if (IS_LL(spec))
		spec->type.unsigned_llong = va_arg(ap, unsigned long long int);
	else if (IS_J(spec))
		spec->type.uintmax = va_arg(ap, uintmax_t);
	else if (IS_Z(spec))
		spec->type.sizet = va_arg(ap, size_t);
	else if (IS_T(spec))
		spec->type.ptr_diff = va_arg(ap, ptrdiff_t);
	else
		spec->type.signed_int = va_arg(ap, uintmax_t);
}

int				parse_cnv(t_fmt *spec, char **fmt, va_list ap)
{
	if (**fmt == 'c')
		spec->type.signed_char = va_arg(ap, int);
	else if (**fmt == 'S' || (**fmt == 's' && IS_L(spec)))
		spec->type.wide_char = va_arg(ap, wchar_t*);
	else if (**fmt == 's')
	{
		if (!(spec->type.str = va_arg(ap, char*)))
			return (1);
		else if (!(spec->type.str = ft_strndup(spec->type.str, -1)))
			return (0);
	}
	else if (**fmt == 'C')
		spec->type.wide_int = va_arg(ap, wint_t);
	else if (**fmt == 'p')
		spec->type.unsigned_llong = va_arg(ap, unsigned long long);
	else if (ft_strchr("dDi", **fmt))
		handle_di(spec, ap);
	else if (ft_strchr("uoxX", **fmt))
		handle_uox(spec, ap);
	else if (**fmt == 'n')
		handle_n(spec, ap);
	else
		spec->type.void_ptr = va_arg(ap, void*);
	return (1);
}
