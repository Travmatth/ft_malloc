/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:39:26 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/07 15:19:56 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** memdup, -- save a copy of a buffer
**
** DESCRIPTION
** The memdup() function allocates sufficient memory for a copy of the
** string s1, does the copy, and returns a pointer to it.  The pointer may
** subsequently be used as an argument to the function free(3).
**
** If insufficient memory is available, NULL is returned and errno is set to
** ENOMEM.
**
** The strndup() function copies at most n characters from the string s1
** always NUL terminating the copied string.
*/

void	*ft_memdup(const void *buffer, size_t len)
{
	void	*dest;

	if (!buffer || !(dest = ft_memalloc(len)))
		return (NULL);
	return (ft_memcpy(dest, buffer, len));
}
