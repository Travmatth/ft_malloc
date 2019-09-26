/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 06:47:20 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/19 14:39: 1by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/internal.h"

/*
** Iterate over given bin and combine consecutive free chunks
*/

void	coalesce_bin(void *bin)
{
	(void)bin;
}

void	free_large_bin(t_chunk *chunk)
{
	g_bins.large_bin = chunk->next;
	munmap(chunk, META_SIZE + OFFSET + chunk->size);
}

/*
** Mark given pointer as a free chunk
*/

void	free(void *pointer)
{
	t_chunk	*chunk;

	if (pointer == NULL || (size_t)pointer % 8)
		return ;
	chunk = GET_CHUNK_POINTER(pointer);
	DEBUG_LOG("Freeing pointer: %p from chunk: %p\n", pointer, (void*)chunk);
	if (!(chunk->metadata & ALLOCED))
	{
		DEBUG_LOG("Error: Attempt to free unallocated chunk %p\n", pointer);
		errno = ENOMEM;
	}
	chunk->metadata &= ~ALLOCED;
	if (chunk->metadata & LARGE_BIN)
		free_large_bin(chunk);
	else
		coalesce_bin(chunk);
}
