/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:00:41 by tmatthew          #+#    #+#             */
/*   Updated: 2018/10/09 23:20:53 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_lstfilter
** Description Iterates list and applies the function *f to each link.
** Removes nodes that return true from the list, deletes node by passing to *d
** Param. #1 A pointer to the first link of a list.
** Param. #2 The address of filter function to apply to each link of a list.
** Param. #3 The address of delete function to apply to removed links.
** Return value the given list, with specified nodes removed and deleted.
** Libc functions None.
*/

t_list	*ft_lstfilter(t_list *list, int (*f)(t_list *elem),
		void (*del)(void *, size_t))
{
	t_list	*result;
	t_list	*next;

	result = NULL;
	while (list)
	{
		next = list->next;
		if (!f(list))
		{
			list->next = NULL;
			ft_lstpushback(&result, list);
		}
		else
			ft_lstdelone(&list, del);
		list = next;
	}
	return (result);
}
