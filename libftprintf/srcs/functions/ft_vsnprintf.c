/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:27:52 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/26 16:39:47 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** DESCRIPTION
** The printf() family of functions produces output according to a format as
** described below. sprintf(), snprintf(), vsprintf(), and vsnprintf()
** write to the character string str;
**
** The snprintf() and vsnprintf() functions will write at most size-1 of the
** characters printed into the output string (the size'th character then
** gets the terminating `\0'); if the return value is greater than or equal
** to the size argument, the string was too short and some of the printed
** characters were discarded.  The output is always null-terminated, unless
** size is 0.
**
** RETURN VALUES
** These functions return the number of characters printed (not including
** the trailing `\0' used to end output to strings)
** These functions return a negative value if an error occurs.
*/

static int		yield_str(t_buf *b, void *p)
{
	t_print	*print_spec;

	if (!b)
		return (0);
	print_spec = (t_print*)p;
	ft_memcpy(print_spec->str, b->buf, b->current);
	return ((int)b->current);
}

int				ft_vsnprintf(char *str
							, size_t size
							, const char *format
							, va_list ap)
{
	int		result;
	t_print	print_spec;

	print_spec.str = str;
	print_spec.size = size;
	result = vfmt_buffer(yield_str, (void*)&print_spec, (char*)format, ap);
	return (result);
}
