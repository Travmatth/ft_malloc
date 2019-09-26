/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:20:06 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:28 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** The isalpha() function tests for any character for which isupper(3) or
** islower(3) is true.  The value of  the argument must be representable as
** an unsigned char or the value of EOF.
*/

int		ft_isascii(int c)
{
	return (c >= 0x00 && c <= 0x7f);
}
