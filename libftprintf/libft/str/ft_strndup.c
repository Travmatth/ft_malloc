/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:39:26 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/07 17:51:43 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** strdup, strndup -- save a copy of a string
**
** DESCRIPTION
** The strdup() function allocates sufficient memory for a copy of the
** string s1, does the copy, and returns a pointer to it.  The pointer may
** subsequently be used as an argument to the function free(3).
**
** If insufficient memory is available, NULL is returned and errno is set to
** ENOMEM.
**
** The strndup() function copies at most n characters from the string s1
** always NUL terminating the copied string.
*/

char	*ft_strndup(const char *s1, int len)
{
	char	*dest;
	size_t	size;

	size = len == -1 ? LEN(s1, 0) : (size_t)len;
	if (!s1 || !(dest = ft_strnew(size)))
		return (NULL);
	return (ft_memcpy(dest, s1, size));
}
