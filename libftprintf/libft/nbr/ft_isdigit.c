/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:20:06 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:26 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** The isdigit() function tests for a decimal digit character.
*/

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
