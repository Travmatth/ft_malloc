/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmergesort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:09:32 by tmatthew          #+#    #+#             */
/*   Updated: 2018/09/28 16:40:04 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_list	*merge(int (*f)(void *first, void *second)
					, t_list *l
					, t_list *r
					, int reverse)
{
	t_list	*sorted;
	int		greater;

	sorted = NULL;
	while (l && r)
	{
		greater = f((void*)l->content, (void*)r->content);
		if (greater)
		{
			(!reverse)
				? ft_lstpushback(&sorted, ft_lsthead(&l))
				: ft_lstpushback(&sorted, ft_lsthead(&r));
		}
		else
		{
			(!reverse)
				? ft_lstpushback(&sorted, ft_lsthead(&r))
				: ft_lstpushback(&sorted, ft_lsthead(&l));
		}
	}
	ft_lstmerge(&sorted, l);
	ft_lstmerge(&sorted, r);
	return (sorted);
}

t_list			*ft_lstmergesort(int (*f)(void *first, void *second)
								, t_list *list
								, int reverse
								, size_t size)
{
	t_list	*left;
	t_list	*right;

	if (!list)
		return (NULL);
	else if (size > 1)
	{
		right = ft_lstsplit(list, (size + 1) / 2);
		left = list;
		left = ft_lstmergesort(f, left, reverse, (size + 1) / 2);
		right = ft_lstmergesort(f, right, reverse, size / 2);
		return (merge(f, left, right, reverse));
	}
	return (list);
}
