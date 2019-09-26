/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_by_delim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:15:17 by tmatthew          #+#    #+#             */
/*   Updated: 2018/07/21 18:36:04 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_uint32_to_chrs input (UINT4) into output (unsigned char).
** Assumes len is a multiple of 4.
*/

unsigned char	*ft_uint32_to_chr(unsigned char *output
	, uint32_t *input
	, unsigned int len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (j < len)
	{
		output[j] = (unsigned char)(input[i] & 0xff);
		output[j + 1] = (unsigned char)((input[i] >> 8) & 0xff);
		output[j + 2] = (unsigned char)((input[i] >> 16) & 0xff);
		output[j + 3] = (unsigned char)((input[i] >> 24) & 0xff);
		i += 1;
		j += 4;
	}
	return (output);
}
