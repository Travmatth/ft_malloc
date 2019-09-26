/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:38:35 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/26 16:43:29 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** memcpy -- copy memory area
**
** DESCRIPTION
** The memcpy() function copies n bytes from memory area src to memory area
** dst.  If dst and src overlap, behavior is undefined.  Applications in
** which dst and src might overlap should use memmove(3) instead.
**
** RETURN VALUES
** The memcpy() function returns the original value of dst.
*/

static size_t	copy_by_chunk(char **dst, const char **src, size_t length)
{
	long		*aligned_dst;
	const long	*aligned_src;

	aligned_dst = (long*)*dst;
	aligned_src = (long*)*src;
	while (length >= BIGBLOCKSIZE)
	{
		*aligned_dst++ = *aligned_src++;
		*aligned_dst++ = *aligned_src++;
		*aligned_dst++ = *aligned_src++;
		*aligned_dst++ = *aligned_src++;
		length -= BIGBLOCKSIZE;
	}
	*dst = (char*)aligned_dst;
	*src = (char*)aligned_src;
	return (length);
}

void			*ft_memcpy(void *dst_void, const void *src_void, size_t len)
{
	char		*dst;
	const char	*src;
	long		*aligned_dst;
	const long	*aligned_src;

	if (!(dst_void && src_void))
		return (NULL);
	dst = (char*)dst_void;
	src = (char*)src_void;
	while (len != 0 && NOT_LONG_BOUNDARY(dst) && len--)
		*dst++ = *src++;
	if (!TOO_SMALL(len) && !UNALIGNED(src, dst))
		len = copy_by_chunk(&dst, &src, len);
	aligned_dst = (long*)dst;
	aligned_src = (long*)src;
	while (len >= LITTLEBLOCKSIZE && !UNALIGNED(src, dst))
	{
		*aligned_dst++ = *aligned_src++;
		len -= LITTLEBLOCKSIZE;
	}
	dst = (char*)aligned_dst;
	src = (char*)aligned_src;
	while (len--)
		*dst++ = *src++;
	return (dst_void);
}
