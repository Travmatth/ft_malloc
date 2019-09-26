/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushparams.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:50:53 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:57 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstpushparams(int ac, char **av)
{
	t_list	*node;
	t_list	*tmp;
	int		offset;

	node = 0;
	offset = 0;
	while (++offset < ac)
	{
		tmp = ft_lstnew(av[offset], ft_strlen(av[offset]));
		tmp->next = node;
		node = tmp;
	}
	return (node);
}
