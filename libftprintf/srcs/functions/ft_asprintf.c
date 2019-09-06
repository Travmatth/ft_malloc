/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:27:52 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/25 20:17:33 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** asprintf() and vasprintf() dynamically allocate a new string with malloc(3).
**
** The asprintf() and vasprintf() functions set *ret to be a pointer to a
** buffer sufficiently large to hold the formatted string.  This pointer
** should be passed to free(3) to release the allocated storage when it is
** no longer needed.	If sufficient space cannot be allocated, asprintf()
** and vasprintf() will return -1 and set ret to be a NULL pointer.
** RETURN VALUES
** These functions return the number of characters printed (not including
** the trailing `\0' used to end output to strings)
** These functions return a negative value if an error occurs.
*/

int		ft_asprintf(char **ret, const char *format, ...)
{
	va_list ap;
	int		result;

	va_start(ap, format);
	result = ft_vasprintf(ret, (char*)format, ap);
	va_end(ap);
	return (result);
}
