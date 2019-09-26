/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:48:55 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:30:07 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** strcat, strncat -- concatenate strings
**
** DESCRIPTION
** The strcat() and strncat() functions append a copy of the null-terminated
** string s2 to the end of the null-terminated string s1, then add a termi-
** nating `\0'.  The string s1 must have sufficient space to hold the
** result.
**
** The strncat() function appends not more than n characters from s2, and
** then adds a terminating `\0'.
**
** The source and destination strings should not overlap, as the behavior is
** undefined.
**
** RETURN VALUES
** The strcat() and strncat() functions return the pointer s1.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s2_i;
	size_t	s1_i;

	s2_i = 0;
	s1_i = 0;
	while (*(s1 + s1_i))
		s1_i += 1;
	while (s2_i < n && *(s2 + s2_i))
		*(s1 + s1_i++) = *(s2 + s2_i++);
	*(s1 + s1_i) = '\0';
	return (s1);
}
