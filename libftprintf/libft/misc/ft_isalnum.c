/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:43:25 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:24 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** The isalnum() function tests for any character for which isalpha(3) or
** isdigit(3) is true.  The value of the argument must be representable as
** an unsigned char or the value of EOF.
*/

int		ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
