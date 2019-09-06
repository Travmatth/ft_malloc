/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:22:57 by tmatthew          #+#    #+#             */
/*   Updated: 2018/10/31 17:51:21 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_freearr(char **arr, int free_parent)
{
	int		i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	if (free_parent)
		free(arr);
}
