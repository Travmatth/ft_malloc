/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:00:45 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/30 14:24:36 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/internal.h"

size_t			ft_intmaxtoa_base(char *string
							, intmax_t nbr
							, int8_t base
							, const char *lookup)
{
	uintmax_t	index;
	size_t		len;
	size_t		out;

	index = nbr;
	len = 1;
	while ((index /= base))
		len++;
	out = len;
	index = nbr;
	string[len] = '\0';
	string[--len] = lookup[index % base];
	while ((index /= base))
		string[--len] = lookup[index % base];
	return (out);
}

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

void			*ft_memmove(void *dst_void, const void *src_void, size_t length)
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
			? copy_by_chunk(&dst, &src, length) : length;
		while (length--)
			*dst++ = *src++;
	}
	return (dst_void);
}
