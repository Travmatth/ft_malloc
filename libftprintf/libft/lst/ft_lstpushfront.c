/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:58:00 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:01 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstpushfront(t_list **begin_list, t_list *node)
{
	t_list	*prev;

	prev = *begin_list;
	*begin_list = node;
	(*begin_list)->next = prev;
	return (*begin_list);
}
