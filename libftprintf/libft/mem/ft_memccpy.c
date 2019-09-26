/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:37:20 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:10 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** memccpy -- copy string until character found
**
** DESCRIPTION
** The memccpy() function copies bytes from string src to string dst.  If
** the character c (as converted to an unsigned char) occurs in the string
** src, the copy stops and a pointer to the byte after the copy of c in the
** string dst is returned.  Otherwise, n bytes are copied, and a NULL
** pointer is returned.
**
** The source and destination strings should not overlap, as the behavior is
** undefined.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	i = 0;
	src_ptr = (unsigned char*)src;
	dst_ptr = (unsigned char*)dst;
	while (i < n)
	{
		*(dst_ptr + i) = *src_ptr++;
		if (*(dst_ptr + i++) == (unsigned char)c)
			return (void*)(dst_ptr + i);
	}
	return (NULL);
}
