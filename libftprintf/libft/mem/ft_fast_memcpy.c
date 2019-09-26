/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:38:35 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:08 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	int		within_bounds(
	size_t *n, int mover, void **str1_tmp, const void **str2)
{
	return ((*n -= mover)
		&& (*str1_tmp = (char*)*str1_tmp + mover)
		&& (*str2 = (char*)*str2 + mover));
}

static	void	*ft_memcpy_eng(void *str1, const void *str2, size_t n)
{
	int		mover;
	void	*str1_tmp;

	mover = 0;
	str1_tmp = str1;
	while (n > 0 && within_bounds(&n, mover, &str1_tmp, &str2))
	{
		mover = 0;
		if (n >= 8)
		{
			*(long int*)str1_tmp = *(long int*)str2;
			mover = sizeof(long int);
		}
		else if (n >= 4)
		{
			*(int*)str1_tmp = *(int*)str2;
			mover = sizeof(int);
		}
		else
		{
			*(char*)str1_tmp = *(char*)str2;
			mover = sizeof(char);
		}
	}
	return (str1);
}

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

void			*ft_fast_memcpy(void *str1, const void *str2, size_t n)
{
	if (!str1 && !str2 && n == 0)
		return (ft_memcpy_eng(str1, str2, n));
	if (!str1)
		*(long int*)str1 = *(long int*)str1;
	if (!str2)
		*(long int*)str2 = *(long int*)str2;
	return (ft_memcpy_eng(str1, str2, n));
}
