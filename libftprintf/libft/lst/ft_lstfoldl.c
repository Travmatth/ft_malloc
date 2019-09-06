/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfoldl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:09:32 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/04 19:29:10 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_lstfoldl(void *(*f)(void *final
								, t_list *elem
								, size_t i
								, int *stop)
					, t_list *list)
{
	void	*final;
	size_t	i;
	int		stop;

	if (!(f && list))
		return (NULL);
	i = 0;
	stop = 0;
	final = NULL;
	while (!stop && list)
	{
		final = f(final, list, i++, &stop);
		list = list->next;
	}
	return (final);
}
