/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:09:32 by tmatthew          #+#    #+#             */
/*   Updated: 2018/09/28 14:15:47 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstsplit(t_list *list, int index)
{
	int		i;
	t_list	*tail;

	i = 0;
	while (list && i++ < index - 1)
		list = list->next;
	if (!list || !list->next)
		return (NULL);
	tail = list->next;
	list->next = NULL;
	return (tail);
}
