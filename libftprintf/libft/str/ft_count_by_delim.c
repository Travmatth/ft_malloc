/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_by_delim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:15:17 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:11 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_count_by_delim(char const *string, char c)
{
	char	*ptr;
	size_t	words;

	ptr = (char*)string;
	words = 0;
	while (*ptr)
	{
		ptr = ft_skip_delim(ptr, c);
		if (!ptr)
			return (words);
		while (ptr && *ptr && !IS_SEPARATOR(c, *ptr))
		{
			if (string == ptr || IS_SEPARATOR(c, *(ptr - 1)))
				words += 1;
			ptr += 1;
		}
		if (ptr && !*ptr)
			return (words);
		ptr += 1;
	}
	return (words);
}
