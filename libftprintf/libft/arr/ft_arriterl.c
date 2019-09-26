/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arriterl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:22:34 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:37 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_arriterl(void *(*f)(void *elem, size_t i, int *stop)
					, size_t len, size_t step, void *arr)
{
	size_t	i;
	int		stop;

	if (!(f && len && step && arr))
		return (NULL);
	i = 0;
	stop = 0;
	while (!stop && i < len)
	{
		f((void*)&(((char*)arr)[i * step]), i, &stop);
		i += 1;
	}
	return (arr);
}
