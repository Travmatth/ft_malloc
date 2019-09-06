/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:25:00 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:53 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*skip_whitespace(char *s, int step, size_t len)
{
	if (!*s && step == -1)
	{
		s -= 1;
		len -= 1;
	}
	while (len-- > 0 && (*s == ' ' || *s == '\t' || *s == '\n'))
		s += step;
	return (s);
}

/*
** Description
** Allocates (with malloc(3)) and returns a copy of the string
** given as argument without whitespaces at the beginning or at
** the end of the string. Will be considered as whitespaces the
** following characters ’ ’, ’\n’ and ’\t’. If s has no whitespaces
** at the beginning or at the end, the function returns a
** copy of s. If the allocation fails the function returns NULL.
** Param. #1 The string to be trimed.
** Return value The “fresh” trimmed string or a copy of s.
** Libc functions malloc(3)
*/

char		*ft_strtrim(char const *s)
{
	char	*new;
	char	*start;
	char	*end;
	size_t	size;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	start = skip_whitespace((char*)s, 1, len);
	end = skip_whitespace((char*)s + len, -1, len);
	size = end == (char*)s ? 0 : end - start + 1;
	return (!(new = ft_strnew(size))
		? (NULL)
		: ((char*)ft_memcpy((void*)new, (void*)start, size)));
}
