/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:27:52 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/25 20:15:12 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The printf() family of functions produces output according to a format as
** described below. fprintf() and vfprintf() write output
** to the given output stream
**
** RETURN VALUES
** These functions return the number of characters printed (not including
** the trailing `\0' used to end output to strings)
** These functions return a negative value if an error occurs.
*/

int		ft_vfprintf(FILE *stream, const char *format, va_list ap)
{
	(void)stream;
	(void)format;
	(void)ap;
	return (1);
}
