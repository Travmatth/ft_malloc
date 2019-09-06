/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:07:30 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:11 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** The memchr() function locates the first occurrence of c (converted to an
** unsigned char) in string s.
**
** RETURN VALUES
** The memchr() function returns a pointer to the byte located, or NULL if
** no such byte exists within n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_ptr;

	s_ptr = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (*(s_ptr + i++) == (unsigned char)c)
			return (s_ptr + --i);
	}
	return (NULL);
}
