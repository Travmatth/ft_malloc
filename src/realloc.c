/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 06:48:33 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/24 13:00:14 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*realloc(void *pointer, size_t size)
{
	t_chunk	*old_chunk;
	void	*new;
	size_t	new_size;

	if ((size_t)pointer % 8)
	{
		DEBUG_LOG("Realloc attempted on misaligned pointer: %p\n", pointer);
		return (NULL);
	}
	else if (pointer == NULL)
	{
		DEBUG_LOG("Realloc returning new pointer of size: %zu\n", size);
		return (malloc(size));
	}
	old_chunk = GET_CHUNK_POINTER(pointer);
	new_size = MIN(size, old_chunk->size);
	if ((new = malloc(size)) != NULL)
	{
		ft_memcpy((void*)new, pointer, new_size);
		free(pointer);
		DEBUG_LOG("Realloc moved %zu bytes from %p to pointer %p of size: %zu\n"
			, new_size
			, pointer
			, new
			, size);
	}
	else
	{
		DEBUG_LOG("Realloc failed to allocate pointer of size: %zu\n", size);
	}
	return (new);
}
