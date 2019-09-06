/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxtoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:10:50 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/09 15:03:16 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_intmaxtoa_base(intmax_t nbr, int8_t base, const char *lookup)
{
	uintmax_t	index;
	size_t		len;
	char		*string;

	index = nbr < 0 ? -nbr : nbr;
	len = -nbr ? 2 : 1;
	while ((index /= base))
		len++;
	if (!(string = ft_strnew(len)))
		return (NULL);
	index = nbr;
	string[--len] = lookup[index % base];
	while ((index /= base))
		string[--len] = lookup[index % base];
	if (-nbr)
		string[0] = '-';
	return (string);
}
