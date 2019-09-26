/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 14:32:50 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/26 14:33:12 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_wstr_to_str(wchar_t *ws)
{
	char	*str;
	size_t	i;
	size_t	pos;

	i = 0;
	pos = 0;
	str = ft_strnew(ft_wstrlen(ws));
	while (ws[i])
	{
		ft_str_to_unicode(ws[i], str + pos);
		pos += ft_wchrlen(ws[i++]);
	}
	return (str);
}
