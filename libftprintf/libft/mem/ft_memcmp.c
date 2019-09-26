/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:12:57 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:12 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** DESCRIPTION
** The memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
**
** RETURN VALUES
** The memcmp() function returns zero if the two strings are identical, oth-
** erwise returns the difference between the first two differing bytes
** (treated as unsigned char values, so that `\200' is greater than `\0',
** for example).  Zero-length strings are always identical.  This behavior
** is not required by C and portable code should only depend on the sign of
** the returned value.
*/

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = -1;
	while (++i < n && s1[i] == s2[i])
		;
	return (i == n ? 0 : s1[i] - s2[i]);
}
