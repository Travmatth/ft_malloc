/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 06:47:17 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/17 16:45:54 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>

void	*procure_tiny(size_t size)
{
	DEBUG_PRINT("Procuring memory for tiny allocation\n");
	(void)size;
	return (NULL);
}

void	*procure_small(size_t size)
{
	DEBUG_PRINT("Procuring memory for small allocation\n");
	(void)size;
	return (NULL);
}

void	*procure_large(size_t size)
{
	DEBUG_PRINT("Procuring memory for large allocation\n");
	(void)size;
	return (NULL);
}

void	*malloc(size_t size)
{
	void	*ret;

	DEBUG_LOG("Malloc call for %zu bytes\n", size);
	if (size == 0)
	{
		ret = NULL;
	}
	else if (IS_TINY(size))
	{
		ret = procure_tiny(size);
	}
	else if (IS_SMALL(size))
	{
		ret = procure_small(size);
	}
	else
	{
		ret = procure_large(size);
	}
	return (ret);
}
