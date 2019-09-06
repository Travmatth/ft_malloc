/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:12:03 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:59 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** strstr -- locate a substring in a string
**
** DESCRIPTION
** The strstr() function locates the first occurrence of the null-terminated
** string needle in the null-terminated string haystack.
**
** RETURN VALUES
** If needle is an empty string, haystack is returned; if needle occurs
** nowhere in haystack, NULL is returned; otherwise a pointer to the first
** character of the first occurrence of needle is returned.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	needle_i;
	size_t	haystack_i;

	if (!*needle)
		return (char*)(haystack);
	haystack_i = 0;
	while (haystack[haystack_i])
	{
		needle_i = 0;
		while (haystack[haystack_i] == needle[needle_i])
		{
			needle_i += 1;
			haystack_i += 1;
			if (needle[needle_i] == 0)
				return (char*)(haystack + haystack_i - needle_i);
		}
		haystack_i -= needle_i;
		haystack_i += 1;
	}
	return (NULL);
}
