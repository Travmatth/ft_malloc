/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 06:47:17 by tmatthew          #+#    #+#             */
/*   Updated: 2019/10/02 17:05:37 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/internal.h"

t_bins	g_bins;

/*
** split_block splits requested chunk into a chunk of requested size of the
** following empty chunk
*/

void	split_block(t_chunk *chunk, size_t size)
{
	char	*next;
	t_chunk	*next_chunk;

	size += META_SIZE + OFFSET;
	next = (char*)(chunk) + size;
	next_chunk = (t_chunk*)next;
	next_chunk->size = ALIGNED_SIZE(chunk->size) - size;
	next_chunk->metadata = 0;
	next_chunk->next = NULL;
	if (chunk->next != NULL)
		next_chunk->next = chunk->next;
	chunk->next = next_chunk;
	DEBUG_LOG("Chunk %p extra space broken into new chunk %p\n"
			, (void*)chunk
			, (void*)next_chunk);
}

/*
** procure_pointer finds size spaced chunks within mmapped bins, or requests new
** pages if bin does not contain sufficient memory
*/

void	*procure_pointer(size_t size, void **bin, size_t bin_size)
{
	void	*ptr;
	t_chunk	*chunk;
	t_chunk	*last;
	size_t	aligned;

	DEBUG_PRINT("Procuring memory for bin allocation\n");
	aligned = ALIGNED_SIZE(size);
	last = (t_chunk*)*bin;
	if (!*bin && !(*bin = request_space(NULL, bin_size)))
		return (NULL);
	if ((chunk = next_free_chunk(&last, aligned, *bin)) == NULL)
	{
		if ((chunk = request_space(last, bin_size)) == NULL)
			return (chunk);
	}
	else if (ALIGNED_SIZE(chunk->size) > META_SIZE + aligned + OFFSET)
		split_block(chunk, aligned);
	chunk->size = size;
	chunk->metadata |= (ALLOCED | (IS_TINY(size) ? TINY_BIN : SMALL_BIN));
	ptr = GET_MEM_POINTER(chunk);
	if ((size_t)ptr % alignof(max_align_t))
		DEBUG_PRINT("ERROR: Unaligned ptr procured\n");
	DEBUG_LOG("Malloc returning pointer: %p\n", ptr);
	return (ptr);
}

/*
** procure_large directly requests mmapped memory and connects it to large bin
*/

void	*procure_large(size_t size)
{
	t_chunk	*last;
	t_chunk	*chunk;
	void	*ptr;

	DEBUG_PRINT("Procuring memory for large allocation\n");
	if (!g_bins.large_bin && !(g_bins.large_bin = request_space(
		NULL, META_SIZE + size + OFFSET)))
		return (NULL);
	if ((chunk = next_free_chunk(&last, size, g_bins.large_bin)) == NULL)
	{
		if ((chunk = request_space(last, META_SIZE + size + OFFSET)) == NULL)
			return (chunk);
	}
	chunk->metadata |= (ALLOCED | LARGE_BIN);
	chunk->size = size;
	ptr = GET_MEM_POINTER(chunk);
	DEBUG_LOG("Malloc returning pointer: %p\n", ptr);
	return (ptr);
}

/*
** Malloc requests and tracks mmapped memory to allow users
** to request pointers to chunks of size
*/

void	*malloc(size_t size)
{
	void	**bin;
	size_t	bin_size;

	DEBUG_LOG("Malloc call for %zu bytes\n", size);
	if (size <= 0)
		return (NULL);
	else if (IS_LARGE(size))
		return (procure_large(size));
	bin = IS_TINY(size) ? &g_bins.tiny_bin : &g_bins.small_bin;
	bin_size = IS_TINY(size) ? TINY_SIZE : SMALL_SIZE;
	return (procure_pointer(size, bin, bin_size));
}
