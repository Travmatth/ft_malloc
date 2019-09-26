/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:17:16 by tmatthew          #+#    #+#             */
/*   Updated: 2018/07/21 18:37:01 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Convert unsigned string to uint32_t array.
** Assumes len is a multiple of 4.
*/

uint32_t	*ft_chr_to_uint32(uint32_t *output
	, unsigned char *input
	, unsigned int len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (j < len)
	{
		output[i] = ((uint32_t)input[j])
			| (((uint32_t)input[j + 1]) << 8)
			| (((uint32_t)input[j + 2]) << 16)
			| (((uint32_t)input[j + 3]) << 24);
		i += 1;
		j += 4;
	}
	return (output);
}
