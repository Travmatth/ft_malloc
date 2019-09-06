/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint8to64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:48:56 by tmatthew          #+#    #+#             */
/*   Updated: 2018/09/17 18:42:41 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** The ft_uint8to64 function takes string of uint8_t characters
** and converts it to uint64_t
*/

uint64_t	ft_uint8to64(uint8_t *block)
{
	uint8_t		i;
	uint64_t	new;

	new = 0;
	i = 0;
	while (i < 8)
	{
		new |= ((uint64_t)block[i]) << (8 * (8 - (i + 1)));
		i += 1;
	}
	return (new);
}
