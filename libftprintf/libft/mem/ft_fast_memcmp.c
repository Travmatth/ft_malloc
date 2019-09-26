/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:12:57 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:07 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		cmp_bytes(const void *str1, const void *str2, size_t n)
{
	unsigned char *str1_tmp;
	unsigned char *str2_tmp;

	str1_tmp = (unsigned char*)str1;
	str2_tmp = (unsigned char*)str2;
	while (n)
	{
		if (*str1_tmp > *str2_tmp)
			return (*str1_tmp - *str2_tmp);
		else if (*str1_tmp < *str2_tmp)
			return (*str1_tmp - *str2_tmp);
		str1_tmp += 1;
		str2_tmp += 1;
		n -= 1;
	}
	return (0);
}

static void		update_lengths(
	size_t *n, const void **str1, const void **str2, size_t dist)
{
	*n -= dist;
	*(char*)str1 += dist;
	*(char*)str2 += dist;
}

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

int				ft_fast_memcmp(const void *str1, const void *str2, size_t n)
{
	while (n)
	{
		if (n >= LLI_SIZE)
		{
			if ((*(LLI*)str1) != (*(LLI*)str2))
				return (cmp_bytes((LLI*)(str1), (LLI*)str2, LLI_SIZE));
			update_lengths(&n, &str1, &str2, LLI_SIZE);
		}
		else if (n >= LI_SIZE)
		{
			if ((*(long int*)str1) != (*(LI*)str2))
				return (cmp_bytes((LI*)str1, (LI*)str2, LI_SIZE));
			update_lengths(&n, &str1, &str2, LI_SIZE);
		}
		else if (n >= I_SIZE)
		{
			if (*(int*)(str1) != *(int*)(str2))
				return (cmp_bytes((int*)str1, (int*)str2, I_SIZE));
			update_lengths(&n, &str1, &str2, I_SIZE);
		}
		else
			return (cmp_bytes((char*)str1, (char*)str2, n));
	}
	return (0);
}
