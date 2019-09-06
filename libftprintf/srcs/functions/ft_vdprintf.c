/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:27:52 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/26 15:41:08 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The printf() family of functions produces output according to a format as
** described below. dprintf() and vdprintf() write output to the
** given file descriptor
** RETURN VALUES
** These functions return the number of characters printed (not including
** the trailing `\0' used to end output to strings)
** These functions return a negative value if an error occurs.
*/

static int		yield_fd(t_buf *b, void *p)
{
	if (!b)
		return (0);
	return (write(*(int*)p, (char*)(b->buf), b->current));
}

int				ft_vdprintf(int fd, const char *format, va_list ap)
{
	return (vfmt_buffer(yield_fd, (void*)&fd, (char*)format, ap));
}
