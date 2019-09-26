/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:27:52 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/25 20:25:47 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The printf() family of functions produces output according to a format as
** described below.  snprintf(), vsprintf(), and vsnprintf() write to the
** character string str; and asprintf() and vasprintf() dynamically allocate
** a new string with malloc(3).
**
** The snprintf() and vsnprintf() functions will write at most size-1 of the
** characters printed into the output string (the size'th character then
** gets the terminating `\0'); if the return value is greater than or equal
** to the size argument, the string was too short and some of the printed
** characters were discarded.  The output is always null-terminated, unless
** size is 0.
**
** The sprintf() and vsprintf() functions effectively assume a size of
** INT_MAX + 1.
** RETURN VALUES
** These functions return the number of characters printed (not including
** the trailing `\0' used to end output to strings)
** These functions return a negative value if an error occurs.
*/

int		ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list ap;
	int		result;

	va_start(ap, format);
	result = ft_vsnprintf(str, size, (char*)format, ap);
	va_end(ap);
	return (result);
}
