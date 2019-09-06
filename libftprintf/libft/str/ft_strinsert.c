/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:49:11 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/06 14:57:41 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strinsert(const char *str, const char *text, size_t index)
{
	size_t	str_size;
	size_t	text_size;
	char	*new;

	str_size = LEN(str, 0);
	text_size = LEN(text, 0);
	if (!(new = ft_strnew(str_size + text_size)))
		return (NULL);
	ft_memcpy(new, str, index);
	ft_memcpy(new + index, text, text_size);
	ft_memcpy(new + index + text_size, str + index, str_size - index);
	return (new);
}
