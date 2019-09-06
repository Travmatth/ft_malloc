/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:06:33 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:47 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstfind(t_list *begin_list
					, void *data_ref
					, int (*cmp)())
{
	while (begin_list)
	{
		if (cmp(begin_list->content, data_ref, begin_list->content_size))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
