/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 14:31:38 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/26 14:32:09 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_wstrlen(wchar_t *w_str)
{
	size_t	i;
	wchar_t	current;

	i = 0;
	current = *w_str;
	while (current)
	{
		if (current <= 0x7F)
			i++;
		else if (current <= 0x7FF)
			i += 2;
		else if (current <= 0xFFFF)
			i += 3;
		else if (current <= 0x10FFFF)
			i += 4;
		w_str++;
		current = *w_str;
	}
	return (i);
}
