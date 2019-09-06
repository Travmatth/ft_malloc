/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcndremove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:36:37 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:41 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstcndremove(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*node;

	if (!begin_list || !(*begin_list))
		return (NULL);
	node = *begin_list;
	if (node->next)
		ft_lstcndremove(&(node->next), data_ref, cmp);
	if (!((*cmp)(node->content, data_ref, node->content_size)))
		node = node->next;
	return (node);
}
