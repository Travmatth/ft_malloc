/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:42:03 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/10 14:03:01 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** memmove -- copy byte string
**
** DESCRIPTION
** The memmove() function copies len bytes from string src to string dst.
** The two strings may overlap; the copy is always done in a non-destructive
** manner.
** If destructive overlap, have to copy backwards. Else use long cpy
** Use optimizing algorithm for a non-destructive copy to closely
** match memcpy. If the size is small or either SRC or DST is unaligned,
** then punt into the byte copy loop.  This should be rare.
** Copy 4X long words at a time if possible.
** Copy one long word at a time if possible.
** Pick up any residual with a byte copier.
**
** RETURN VALUES
** The memmove() function returns the original value of dst.
*/

size_t	copy_by_chunk(char *dst, const char *src, size_t length)
{
	long		*aligned_dst;
	const long	*aligned_src;

	if (!TOO_SMALL(length) && !UNALIGNED(src, dst))
	{
		aligned_dst = (long*)dst;
		aligned_src = (long*)src;
		while (length >= BIGBLOCKSIZE)
		{
			*aligned_dst++ = *aligned_src++;
			*aligned_dst++ = *aligned_src++;
			*aligned_dst++ = *aligned_src++;
			*aligned_dst++ = *aligned_src++;
			length -= BIGBLOCKSIZE;
		}
		while (length >= LITTLEBLOCKSIZE)
		{
			*aligned_dst++ = *aligned_src++;
			length -= LITTLEBLOCKSIZE;
		}
		dst = (char*)aligned_dst;
		src = (char*)aligned_src;
	}
	return (length);
}

void	*ft_memmove(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src;

	dst = dst_void;
	src = src_void;
	if (src < dst && dst < src + length)
	{
		src += length;
		dst += length;
		while (length--)
			*--dst = *--src;
	}
	else
	{
		length = !TOO_SMALL(length) && !UNALIGNED(src, dst)
			? copy_by_chunk(dst, src, length) : length;
		while (length--)
			*dst++ = *src++;
	}
	return (dst_void);
}
