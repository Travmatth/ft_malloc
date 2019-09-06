/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:34:43 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:36 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_putnbr
** Description Outputs the integer n to the standard output.
** Param. #1 The integer to output.
** Return value None.
** Libc functions write(2).
*/

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}
