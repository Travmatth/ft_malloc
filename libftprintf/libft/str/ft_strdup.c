/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:39:26 by tmatthew          #+#    #+#             */
/*   Updated: 2018/10/10 00:27:33 by tmatthew         ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	if (!s1)
		return (NULL);
	len = LEN(s1, 0);
	if (!(dest = ft_strnew(len)))
		return (NULL);
	return (ft_memcpy(dest, s1, len));
}
