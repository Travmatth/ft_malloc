/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 20:10:08 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:26 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_count_digits(int number)
{
	int		digits;

	digits = 0;
	if (number < 0)
		digits += 1;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		digits += 1;
	}
	return (digits);
}
