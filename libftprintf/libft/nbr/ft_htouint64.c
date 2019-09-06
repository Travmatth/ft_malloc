/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htouint64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:46:46 by tmatthew          #+#    #+#             */
/*   Updated: 2018/09/03 09:54:14 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** The ft_htouint64 function take a uint8_t string of hex characters
** and returns the equivalent uint64_t with those values.
*/

int			ft_htouint64(uint8_t *hex, uint64_t *val)
{
	uint8_t		c;
	uint8_t		i;

	i = 0;
	*val = 0;
	while (i < 16)
	{
		c = hex[i++];
		*val *= 16;
		if (c >= 'A' && c <= 'F')
			*val += c - 'A' + 10;
		else if (c >= 'a' && c <= 'f')
			*val += c - 'a' + 10;
		else if (c >= '0' && c <= '9')
			*val += c - '0';
		else
			return (0);
	}
	return (1);
}
