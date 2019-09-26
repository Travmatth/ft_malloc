/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:42:04 by tmatthew          #+#    #+#             */
/*   Updated: 2018/09/28 14:47:55 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstmerge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *tmp;

	if (!begin_list2)
		return ;
	else if (*begin_list1)
	{
		tmp = *begin_list1;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}
