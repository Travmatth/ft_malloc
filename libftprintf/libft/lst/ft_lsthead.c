/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsthead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:15:30 by tmatthew          #+#    #+#             */
/*   Updated: 2018/09/28 15:24:03 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lsthead(t_list **begin_list)
{
	t_list	*tmp;

	if (!(begin_list && *begin_list))
		return (NULL);
	tmp = *begin_list;
	*begin_list = (*begin_list)->next;
	tmp->next = NULL;
	return (tmp);
}
