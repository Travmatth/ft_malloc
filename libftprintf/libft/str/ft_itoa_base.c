/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:18:37 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/30 19:00:28 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_itoa_base
** Description Allocate (with malloc(3)) and returns a "fresh" string ending
** with "\0"" representing the integer n with given base  as argument.
** Negative numbers must be supported. If the allocation fails,
** the function returns NULL.
** Param. #1 The integer to be transformed into a string.
** Return value The string representing the integer passed as argument.
** Libc functions malloc(3)
*/

char	*ft_itoa_base(int n, int base)
{
	long long	abs_num;
	int			digits;
	char		*str;
	int			sign;

	sign = n < 0 ? 1 : 0;
	digits = ft_count_digits_base(n, base);
	if (!(str = ft_strnew(digits)))
		return (NULL);
	abs_num = sign ? (long long)n * -1 : (long long)n;
	while (--digits > 0)
	{
		str[digits] = '0' + (abs_num % base);
		abs_num /= base;
	}
	str[digits] = sign ? '-' : '0' + (abs_num % base);
	return (str);
}
