/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 06:47:17 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/20 14:24:26 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_bins	g_bins;

void	split_block(t_chunk *chunk, size_t size)
{
	char	*next;
	t_chunk	*next_chunk;

	next = (char*)(chunk) + META_SIZE + size;
	next_chunk = (t_chunk*)next;
	next_chunk->size = chunk->size - size - META_SIZE;
	next_chunk->metadata = 0;
	next_chunk->next = NULL;
	DEBUG_LOG("Chunk %p extra space broken into new chunk %p\n"
			, (void*)chunk
			, (void*)next_chunk);
}

void	*procure_pointer(size_t size, void **bin, size_t bin_size)
{
	t_chunk	*last;
	t_chunk	*chunk;

	DEBUG_PRINT("Procuring memory for bin allocation\n");
	if (!*bin && !(*bin = request_space(NULL, bin_size)))
		return (NULL);
	last = (t_chunk*)*bin;
	if ((chunk = next_free_chunk(&last, size, *bin)) == NULL)
	{
		if ((chunk = request_space(last, size)) == NULL)
			return (chunk);
	}
	else if (chunk->size > size + META_SIZE)
		split_block(chunk, size);
	chunk->metadata |= FREE;
	return ((void*)(chunk + 1));
}

void	*procure_large(size_t size)
{
	t_chunk	*last;
	t_chunk	*chunk;

	DEBUG_PRINT("Procuring memory for large allocation\n");
	if (!g_bins.large_bin && !(g_bins.large_bin = request_space(NULL, size)))
		return (NULL);
	last = (t_chunk*)g_bins.large_bin;
	if ((chunk = next_free_chunk(&last, size, g_bins.large_bin)) == NULL)
	{
		if ((chunk = request_space(last, size)) == NULL)
			return (chunk);
	}
	else if (chunk->size > size + META_SIZE)
		split_block(chunk, size);
	chunk->metadata |= FREE;
	return ((void*)(chunk + 1));
}

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
