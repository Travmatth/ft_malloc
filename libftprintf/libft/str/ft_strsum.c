/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:28:56 by tmatthew          #+#    #+#             */
/*   Updated: 2019/05/16 12:39:05 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_strsum - concatenate a null-delimited array of char pointers
*/

char	*free_str(char *str)
{
	free(str);
	return (NULL);
}

char	*ft_strsum(char **strings, char *fill)
{
	int		i;
	int		size;
	char	*str;
	char	*tmp;

	size = 0;
	if (!strings)
		return (NULL);
	while (strings[size])
		size += 1;
	i = 0;
	tmp = NULL;
	if (!size || !(str = ft_strdup(strings[i++])))
		return (NULL);
	while (i < size)
	{
		if (!(tmp = ft_strjoin(str, fill)))
			return (free_str(str));
		free(str);
		if (!(str = ft_strjoin(tmp, strings[i])))
			return (free_str(tmp));
		free(tmp);
		i += 1;
	}
	return (str);
}
