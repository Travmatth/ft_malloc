/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arriter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:01:54 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 19:46:11 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_arriter(void (*f)(void *elem, size_t i)
					, size_t len
					, size_t step
					, void *arr)
{
	size_t	i;
	int		*ptr;

	if (!f || len == 0 || step == 0 || !arr)
		return (NULL);
	i = 0;
	ptr = arr;
	while (i++ < len)
	{
		f(ptr, i);
		ptr += step;
	}
	return (arr);
}
