/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:07:24 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/30 17:37:45 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/internal.h"

/*
** Wrapper to mmap to detect failed mapping
*/

void	*alloc_mem(size_t size)
{
	void	*ret;

	ret = mmap(NULL, size, MMAP_PROTECTIONS, MMAP_FLAGS, 0, 0);
	if (ret == MAP_FAILED)
		return (NULL);
	return (ret);
}

/*
** If bin does not contain a chunk of size, map additional memory to bin
*/

t_chunk	*request_space(t_chunk *last, size_t size)
{
	t_chunk	*chunk;

	DEBUG_LOG("Calling mmap for %zu bytes\n", size);
	if ((chunk = (t_chunk*)alloc_mem(size)) == NULL)
		return (chunk);
	if (last)
		last->next = chunk;
	chunk->size = size;
	chunk->next = NULL;
	chunk->metadata = 0;
	chunk->metadata |= BLOCK;
	return (chunk);
}

/*
** Iterate through the bin and locate the first free block of sufficient size
*/

t_chunk	*next_free_chunk(t_chunk **last, size_t size, void *bin)
{
	t_chunk	*curr;

	curr = (t_chunk *)bin;
	while (curr && (!!(curr->metadata & ALLOCED) || (curr->size < size)))
	{
		*last = curr;
		curr = curr->next;
	}
	if (curr != NULL)
		DEBUG_LOG("Free chunk found to allocate: %p\n", (void*)curr);
	return (curr);
}
