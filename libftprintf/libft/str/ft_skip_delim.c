/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_delim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:13:14 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:32 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_skip_delim(char const *str, char delim)
{
	if (!str || !*str)
		return (NULL);
	while (*str && IS_SEPARATOR(delim, *str))
		str += 1;
	return (*str ? (char*)str : NULL);
}
