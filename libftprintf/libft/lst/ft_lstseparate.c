/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstseparate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:11:16 by tmatthew          #+#    #+#             */
/*   Updated: 2018/10/07 17:23:05 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_lstseparate
** Description Iterates list and applies the function *f to each link.
** Separates nodes that return true from the list
** Sets original list given to nodes that returned false
** Param. #1 A pointer to the first link of a list.
** Param. #2 The address of separate function to apply to each link of a list.
** Param. #3 The address of delete function to apply to removed links.
** Return value the given list, with specified nodes that returned true
** Libc functions None.
*/

t_list	*ft_lstseparate(t_list **list, int (*f)(t_list *elem))
{
	t_list	*result;
	t_list	*current;
	t_list	*orig;
	t_list	*next;

	result = NULL;
	orig = NULL;
	current = *list;
	while (current)
	{
		next = current->next;
		if (f(current))
		{
			current->next = NULL;
			ft_lstpushback(&result, current);
		}
		else
		{
			current->next = NULL;
			ft_lstpushback(&orig, current);
		}
		current = next;
	}
	*list = orig;
	return (result);
}
