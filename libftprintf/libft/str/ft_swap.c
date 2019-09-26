/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:27:30 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/26 16:41:48 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*strend(const char *string)
{
	if (string)
		while (*string)
			string += 1;
	return ((char*)string);
}

/*
** ft_swap
** replaces first occurrence of old with new, return heap allocated str
*/

char		*ft_swap(const char *str, const char *old, const char *new)
{
	char	*swapped;
	char	*location;
	char	*sizes[3];
	size_t	new_size;

	if (!(str && old && new))
		return (NULL);
	if (!(location = ft_strstr(str, old)))
		return (ft_strdup(str));
	sizes[0] = strend(str);
	sizes[1] = strend(old);
	sizes[2] = strend(new);
	new_size = location - str;
	new_size = new_size + (sizes[2] - new);
	new_size = new_size + (sizes[0] - str);
	new_size = new_size - (sizes[1] - old);
	if (!(swapped = ft_strnew(new_size)))
		return (NULL);
	ft_strncpy(swapped, str, location - str);
	ft_strcpy(swapped + (location - str), new);
	ft_strcpy(swapped + (location - str) + (sizes[2] - new)
			, location + (sizes[1] - old));
	return (swapped);
}
