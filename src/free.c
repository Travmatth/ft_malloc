/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 06:47:20 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/28 19:04:04 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/internal.h"

/*
** Iterate over chunks and verify all chunks within bin are free
*/

int		all_chunks_free(t_chunk *chunk)
{
	t_chunk	*next;

	if (!chunk || (chunk->metadata & ALLOCED))
		return (0);
	next = chunk;
	while (next)
	{
		if (next->metadata & BLOCK)
			return (1);
		else if (next->metadata & ALLOCED)
			return (0);
		next = next->next;
	}
	return (0);
}

/*
** munmap bin if all chunks unused
*/

void	free_bin(void **bin)
{
	t_chunk	*c;
	int		can_free;
	int		val;

	while ((c = *(t_chunk**)bin))
	{
		can_free = (c && IS_EMPTY(c));
		can_free = can_free && (!c->next || IS_EMPTY(c->next));
		if (can_free && all_chunks_free(c))
		{
			*bin = c->next;
			val = munmap(c, META_SIZE + OFFSET + c->size);
			DEBUG_LOG("Munmap block %p: %d\n", (void*)c, val);
		}
		else
			*bin = c->next;
	}
}

/*
** Iterate over given bin and combine consecutive free chunks,
** munmap bins if unused
*/

void	coalesce_bin(void **bin)
{
	t_chunk	*next;
	t_chunk	*c;

	c = *(t_chunk**)bin;
	while (c)
	{
		next = c->next;
		while (next && ~(c->metadata & ALLOCED) && ~(next->metadata & ALLOCED))
		{
			DEBUG_LOG("Combining chunks %p, %p\n", (void*)c, (void*)next);
			c->size += META_SIZE + OFFSET + next->size;
			c->next = next->next;
			next = next->next;
		}
		c = next;
	}
	free_bin(bin);
}

/*
** free_large_bin finds and munmaps the given chunk, connects
** large_bin to the next chunk
*/

void	free_large_bin(t_chunk *chunk)
{
	t_chunk	*current;
	int		val;

	current = g_bins.large_bin;
	while (current && current->next && current->next != chunk)
		current = current->next;
	if (current)
		current->next = chunk->next;
	val = munmap(chunk, META_SIZE + OFFSET + chunk->size);
	DEBUG_LOG("Munmap large chunk %p: %d\n", (void*)chunk, val);
}

/*
** Mark given pointer as a free chunk
*/

void	free(void *pointer)
{
	void	*bin;
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
	{
		free_large_bin(chunk);
		return ;
	}
	bin = IS_TINY(chunk->size) ? &g_bins.tiny_bin : &g_bins.small_bin;
	coalesce_bin(bin);
}
