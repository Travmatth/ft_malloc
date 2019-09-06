/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:23:00 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:34 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** strchr -- locate character in string
**
** DESCRIPTION
** The strchr() function locates the first occurrence of c (converted to a
** char) in the string pointed to by s.  The terminating null character is
** considered to be part of the string; therefore if c is `\0', the func-
** tions locate the terminating `\0'.
**
** RETURN VALUES
** The function strchr() returns a pointer to the located
** character, or NULL if the character does not appear in the string.
*/

char	*ft_strchr(const char *s, int c)
{
	if (!*s)
		return (NULL);
	while (*s)
	{
		if (*s++ == c)
			return (char*)(--s);
	}
	return ((char)*s == c ? (char*)s : (NULL));
}
