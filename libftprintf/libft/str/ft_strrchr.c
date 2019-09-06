/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:11:56 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:30:02 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** strchr, strrchr -- locate character in string
**
** DESCRIPTION
** The strchr() function locates the first occurrence of c (converted to a
** char) in the string pointed to by s.  The terminating null character is
** considered to be part of the string; therefore if c is `\0', the functions
** locate the terminating `\0'.
**
** The strrchr() function is identical to strchr(), except it locates the
** last occurrence of c.
**
** RETURN VALUES
** The functions strchr() and strrchr() return a pointer to the located
** character, or NULL if the character does not appear in the string.
*/

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (*s)
	{
		s += 1;
		i += 1;
	}
	while (i >= 0)
	{
		if (*s == (unsigned char)c)
			return ((char*)s);
		s -= 1;
		i -= 1;
	}
	return (NULL);
}
