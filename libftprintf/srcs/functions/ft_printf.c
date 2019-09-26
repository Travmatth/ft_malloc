/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:27:52 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/25 19:47:09 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The printf() family of functions produces output according to a format as
** described below.
**
** RETURN VALUES
** These functions return the number of characters printed (not including
** the trailing `\0' used to end output to strings), except for snprintf()
** and vsnprintf(), which return the number of characters that would have
** been printed if the size were unlimited (again, not including the final
** `\0').  These functions return a negative value if an error occurs.
*/

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		result;

	va_start(ap, format);
	result = ft_vprintf((char*)format, ap);
	va_end(ap);
	return (result);
}
