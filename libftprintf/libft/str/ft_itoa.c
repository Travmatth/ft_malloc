/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:45:46 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:30 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_itoa
** Description Allocate (with malloc(3)) and returns a “fresh” string ending
** with ’\0’ representing the integer n given as argument.
** Negative numbers must be supported. If the allocation fails,
** the function returns NULL.
** Param. #1 The integer to be transformed into a string.
** Return value The string representing the integer passed as argument.
** Libc functions malloc(3)
*/

char	*ft_itoa(int n)
{
	long long	abs_num;
	int			digits;
	char		*str;
	int			sign;

	sign = n < 0 ? 1 : 0;
	digits = ft_count_digits(n);
	if (!(str = ft_strnew(digits)))
		return (NULL);
	abs_num = sign ? (long long)n * -1 : (long long)n;
	while (--digits > 0)
	{
		str[digits] = '0' + (abs_num % 10);
		abs_num /= 10;
	}
	str[digits] = sign ? '-' : '0' + (abs_num % 10);
	return (str);
}
