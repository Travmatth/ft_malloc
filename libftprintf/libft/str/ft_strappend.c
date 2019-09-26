/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:15:17 by tmatthew          #+#    #+#             */
/*   Updated: 2019/03/23 16:09:53 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_strappend(char **strings, char *string)
{
	int		i;
	char	**new;

	if (!strings)
		return (NULL);
	else if (!string)
		return (strings);
	i = 0;
	while (strings[i])
		i += 1;
	if (!(new = (char**)ft_memalloc(sizeof(char*) * (i + 2))))
		return (NULL);
	new[i] = string;
	while (--i >= 0)
		new[i] = strings[i];
	return (new);
}
