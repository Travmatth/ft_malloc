/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:05:03 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:02 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_lstsize(t_list *begin_list)
{
	int		count;
	t_list	*current;

	count = 0;
	current = begin_list;
	while (current)
	{
		count += 1;
		current = current->next;
	}
	return (count);
}
