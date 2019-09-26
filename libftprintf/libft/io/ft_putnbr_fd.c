/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:54:14 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:34 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_putnbr_fd
** Description Outputs the integer n to the file descriptor fd.
** Param. #1 The integer to print.
** Param. #2 The file descriptor.
** Return value None.
** Libc functions write(2).
*/

void	ft_putnbr_fd(int n, int fd)
{
	long long int	current;

	current = n;
	if (current < 0)
	{
		ft_putchar_fd('-', fd);
		current *= -1;
	}
	if (current >= 10)
	{
		ft_putnbr_fd(current / 10, fd);
	}
	ft_putchar_fd('0' + current % 10, fd);
}
