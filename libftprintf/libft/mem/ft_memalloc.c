/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:54:47 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:09 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_memalloc
** Description Allocates (with malloc(3)) and returns a “fresh” memory
** area. The memory allocated is initialized to 0. If the allocation
** fails, the function returns NULL.
** Param. #1 The size of the memory that needs to be allocated.
** Return value The allocated memory area.
** Libc functions malloc(3)
*/

void	*ft_memalloc(size_t size)
{
	size_t			index;
	unsigned char	*ptr;

	if ((ptr = malloc(size)) == 0)
		return (NULL);
	index = 0;
	while (index < size)
	{
		*(ptr + index) = 0;
		index += 1;
	}
	return (void*)(ptr);
}
