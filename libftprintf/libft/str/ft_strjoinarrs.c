/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinarrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:22:32 by tmatthew          #+#    #+#             */
/*   Updated: 2019/04/26 15:23:03 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Create a new char* array by joing two arrays into one
*/

char	**ft_strjoinarrs(char **arr_1, char **arr_2)
{
	int		i;
	int		arr_1_len;
	char	**new;

	i = 0;
	arr_1_len = 0;
	while (arr_1 && arr_1[arr_1_len])
		arr_1_len += 1;
	while (arr_2[i])
		i += 1;
	if (!(new = ft_memalloc(sizeof(char*) * (arr_1_len + i + 1))))
		return (NULL);
	i = -1;
	while (arr_1 && arr_1[++i])
		new[i] = arr_1[i];
	arr_1_len = i >= 0 ? i : 0;
	i = -1;
	while (arr_2[++i])
		new[arr_1_len + i] = arr_2[i];
	return (new);
}
