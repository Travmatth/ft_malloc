/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:27:56 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:30:01 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** strnstr -- locate a substring in a string
**
** DESCRIPTION
** The strnstr() function locates the first occurrence of the null-termi-
** nated string needle in the string haystack, where not more than len char-
** acters are searched.  Characters that appear after a `\0' character are
** not searched.  Since the strnstr() function is a FreeBSD specific API, it
** should only be used when portability is not a concern.
**
** RETURN VALUES
** If needle is an empty string, haystack is returned; if needle occurs
** nowhere in haystack, NULL is returned; otherwise a pointer to the first
** character of the first occurrence of needle is returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	i = 0;
	if (needle[0] == '\0')
		return (char *)(haystack);
	while (i < (int)len && haystack[i] != '\0')
	{
		j = 0;
		while (i < (int)len && j < (int)len && haystack[i] == needle[j])
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)(haystack + (i - j)));
		}
		i -= j;
		i++;
	}
	return (NULL);
}
