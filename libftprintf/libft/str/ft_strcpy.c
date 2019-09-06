/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:18:37 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:39 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** strcpy -- copy strings
**
** DESCRIPTION
** The stpcpy() and strcpy() functions copy the string src to dst (including
** the terminating `\0' character.)
**
** The source and destination strings should not overlap, as the behavior is
** undefined.
**
** RETURN VALUES
** The strcpy() and strncpy() functions return dst.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	char	*ptr;

	ptr = dst;
	while (*src)
		*dst++ = *src++;
	*dst = *src;
	return (ptr);
}
