/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:27:52 by tmatthew          #+#    #+#             */
/*   Updated: 2018/10/09 00:33:18 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The printf() family of functions produces output according to a format as
** described below. asprintf() and vasprintf() dynamically allocate a new
** string with malloc(3).
**
** The asprintf() and vasprintf() functions set *ret to be a pointer to a
** buffer sufficiently large to hold the formatted string.  This pointer
** should be passed to free(3) to release the allocated storage when it is
** no longer needed.	If sufficient space cannot be allocated, asprintf()
** and vasprintf() will return -1 and set ret to be a NULL pointer.
**
** RETURN VALUES
** These functions return the number of characters printed (not including
** the trailing `\0' used to end output to strings)
** These functions return a negative value if an error occurs.
*/

static int		yield_str(t_buf *b, void *p)
{
	if (!b)
		return (0);
	else if ((*(char**)p = ft_strndup(b->buf, b->current)))
		return ((int)b->current);
	else
		return (-1);
}

int				ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int		result;
	int		fd;

	fd = 1;
	result = vfmt_buffer(yield_str, (void*)ret, (char*)format, ap);
	return (result);
}
