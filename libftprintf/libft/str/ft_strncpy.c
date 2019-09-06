/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:25:57 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:30:05 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** stpcpy, stpncpy, strcpy, strncpy -- copy strings
** DESCRIPTION
** The stpcpy() and strcpy() functions copy the string src to dst (including
** the terminating `\0' character.)
**
** The stpncpy() and strncpy() functions copy at most len characters from
** src into dst.  If src is less than len characters long, the remainder of
** dst is filled with `\0' characters.  Otherwise, dst is not terminated.
**
** The source and destination strings should not overlap, as the behavior is
** undefined.
**
** RETURN VALUES
** The strcpy() and strncpy() functions return dst.  The stpcpy() and
** stpncpy() functions return a pointer to the terminating `\0' character of
** dst.  If stpncpy() does not terminate dst with a NUL character, it
** instead returns a pointer to dst[n] (which does not necessarily refer to
** a valid memory location.)
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;
	char	*tmp;

	index = 0;
	tmp = dst;
	while (src[index] && index < len)
	{
		tmp[index] = src[index];
		index += 1;
	}
	while (index < len)
	{
		tmp[index] = '\0';
		index += 1;
	}
	return (tmp);
}
