/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:04:50 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:58 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstpushback(t_list **begin_list, t_list *node)
{
	t_list	*current;

	if (!begin_list)
		return (NULL);
	if (!*begin_list)
		return (*begin_list = node);
	current = *begin_list;
	if (!(current))
	{
		*begin_list = node;
		return (*begin_list);
	}
	while (current->next)
		current = current->next;
	current->next = node;
	return (*begin_list);
}
