/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:15:17 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/24 21:49:14 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_count_char(char const *string, char c)
{
	size_t	chars;

	if (!string)
		return (0);
	chars = 0;
	while (*string)
	{
		if ((unsigned)*string++ == (unsigned)c)
			chars += 1;
	}
	return (chars);
}
