/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stripquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:25:03 by tmatthew          #+#    #+#             */
/*   Updated: 2019/04/26 15:25:32 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Create copy of given string, less the beginning and ending characters
*/

char	*ft_stripquote(char *str)
{
	size_t	len;
	char	*new;

	len = LEN(str, 0);
	new = ft_strnew(len - 2);
	ft_memcpy(new, &str[1], len - 2);
	return (new);
}
