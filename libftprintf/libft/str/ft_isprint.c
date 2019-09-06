/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:53:44 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:31 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** The isprint() function tests for any printing character,
** including space (` ').  The value of the argument
** must be representable as an unsigned char or the value of EOF.
*/

int		ft_isprint(int c)
{
	return ((c >= 32 && c <= 126) || c == ' ');
}
