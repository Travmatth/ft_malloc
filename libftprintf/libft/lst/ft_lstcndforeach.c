/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcndforeach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:52:42 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 19:48:09 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstcndforeach(t_list *begin_list
						, void (*f)(void *, size_t)
						, void *data_ref
						, int (*cmp)())
{
	while (begin_list)
	{
		if (cmp(begin_list->content, data_ref, begin_list->content_size) == 0)
			f(begin_list->content, begin_list->content_size);
		begin_list = begin_list->next;
	}
}
