/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotestr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:24:06 by tmatthew          #+#    #+#             */
/*   Updated: 2019/04/26 15:24:55 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Enclosed given string with specified quote character
*/

char	*ft_quotestr(char *str, char quote)
{
	size_t	len;
	char	*new;

	if (!str)
		return (NULL);
	len = LEN(str, 0);
	if (!(new = ft_strnew(len + 2)))
		return (NULL);
	new[0] = quote;
	return (ft_strncat(ft_strcat(new, str), &quote, 1));
}
