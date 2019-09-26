/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:18:44 by tmatthew          #+#    #+#             */
/*   Updated: 2018/09/30 18:46:27 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**t_list		*ft_lsttail_(t_list **lst)
**{
**	if (!lst || !(*lst) || !((*lst)->next))
**		return (*lst);
**	return (ft_lsttail_(&((*lst)->next)));
**}
*/

t_list	*ft_lsttail(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*node;

	if (!(begin_list && *begin_list))
		return (NULL);
	node = *begin_list;
	if (!node->next)
	{
		tmp = *begin_list;
		*begin_list = NULL;
		return (tmp);
	}
	while (node->next && node->next->next)
		node = node->next;
	tmp = node->next;
	node->next = NULL;
	return (tmp);
}
