/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfoldl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:09:32 by tmatthew          #+#    #+#             */
/*   Updated: 2018/11/19 14:37:08 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_arrfoldl(void *(*f)(void *final, void *elem, size_t i, int *stop)
					, size_t len
					, size_t step
					, void *arr)
{
	void	*final;
	size_t	i;
	int		stop;

	if (!(f && len && step && arr))
		return (NULL);
	i = 0;
	stop = 0;
	final = NULL;
	while (!stop && i < len)
	{
		final = f(final, (void*)&(((char*)arr)[i * step]), i, &stop);
		i += 1;
	}
	return (final);
}
