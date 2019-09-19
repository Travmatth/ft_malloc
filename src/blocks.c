/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:07:24 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/18 17:08:08 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

/*
** Wrapper to mmap to detect failed mapping
*/
void	*alloc_mem(size_t size)
{
	void	*ret;

	ret = mmap(NULL, size, MMAP_PROTECTIONS, MMAP_FLAGS, 0, 0);
	if (ret == MAP_FAILED)
		return NULL;
	return (ret);
}

/*
** If bin does not contain a chunk of size, map additional memory to bin
*/

t_chunk	*request_space(t_chunk *last, size_t size)
{
	t_chunk	*chunk;

	DEBUG_LOG("Calling mmap for %zu bytes (excluding metadata)\n", size);
	if ((chunk = alloc_mem(size + META_SIZE)) == NULL)
		return (chunk);
	if (last)
		last->next = chunk;
	chunk->size = size;
	chunk->next = NULL;
	chunk->metadata |= FREE;
	return (chunk);
}

/*
** Iterate through the bin and locate the first free block of sufficient size
*/

t_chunk	*next_free_chunk(t_chunk **last, size_t size, void *bin)
{
	t_chunk	*current;

	current = (t_chunk *)bin;
	while (current && !((current->metadata & FREE) && current->size >= size))
	{
		*last = current;
		current = current->next;
	}
	DEBUG_LOG("Free chunk found available to allocate: %p\n", (void*)current);
	return (current);
}
