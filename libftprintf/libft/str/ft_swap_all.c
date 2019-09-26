/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:13:50 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/24 22:22:02 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_swap_all
** replaces all occurrences of old in string with new, return heap allocated str
*/

char	*ft_swap_all(const char *str, const char *old, const char *new)
{
	char	*tmp;
	char	*swapped;

	if (!str
		|| !ft_strstr(str, old)
		|| !(swapped = ft_strdup(str)))
		return (NULL);
	tmp = ft_swap(swapped, old, new);
	ft_strdel(&swapped);
	swapped = tmp;
	while (ft_strstr(swapped, old))
	{
		tmp = ft_swap(swapped, old, new);
		ft_strdel(&swapped);
		swapped = tmp;
	}
	return (swapped);
}
