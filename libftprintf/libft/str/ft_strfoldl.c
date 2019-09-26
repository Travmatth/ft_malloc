/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfoldl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:30:13 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/01 17:32:24 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_strfoldl(void *(*f)(void *final, char elem, size_t i, int *stop)
					, size_t len
					, char *arr)
{
	void	*final;
	size_t	i;
	int		stop;

	if (!(f && len && arr))
		return (NULL);
	i = 0;
	stop = 0;
	final = NULL;
	while (!stop && i < len)
	{
		final = f(final, arr[i], i, &stop);
		i += 1;
	}
	return (final);
}
