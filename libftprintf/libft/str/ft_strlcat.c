/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:49:43 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:45 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** strlcat -- size-bounded string copying and concatenation
**
** DESCRIPTION
** strlcpy() and strlcat() take the full size of the destination buffer and
** guarantee NUL-termination if there is room.  Note that room for the NUL
** should be included in dstsize.
**
** strlcat() appends string src to the end of dst.  It will append at most
** dstsize - ft_strlen(dst) - 1 char.  It will then NUL-terminate, unless
** dstsize is 0 or the original dst string was longer than dstsize (in prac-
** tice this should not happen as it means that either dstsize is incorrect
** or that dst is not a proper string).
**
** If the src and dst strings overlap, the behavior is undefined.
**
** RETURN VALUES
** The strlcat() func return the total len of the string it tried to create.
** For strlcat() that means the initial length of dst plus the length of src.
**
** If the return value is >= dstsize, the output string has been truncated.
** It is the caller's responsibility to handle this.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int j;
	unsigned int result;

	i = 0;
	while (dst[i] != '\0')
		++i;
	result = 0;
	while (src[result] != '\0')
		++result;
	if (dstsize <= i)
		result = result + dstsize;
	else
		result = result + i;
	j = 0;
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (result);
}
