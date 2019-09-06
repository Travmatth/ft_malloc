/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:42:03 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:28 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_putchar
** Description Outputs the character c to the standard output.
** Param. #1 The character to output.
** Return value None.
** Libc functions write(2).
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
