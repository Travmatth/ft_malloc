/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:05:53 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:42 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstat(t_list *begin_list, unsigned int nbr)
{
	int		i;
	t_list	*node;

	i = -1;
	node = begin_list;
	while (++i < (int)nbr)
	{
		if (node && !node->next)
			return (0);
		else if (node)
			node = node->next;
	}
	return (node);
}
