/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:16:39 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 21:42:36 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_count_digits_base(int number, int base)
{
	int		digits;

	digits = 0;
	if (number < 0)
		digits += 1;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= base;
		digits += 1;
	}
	return (digits);
}
