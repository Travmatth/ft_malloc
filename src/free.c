/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 06:47:20 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/30 19:02:46 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/internal.h"

/*
** Once unused allocation has been identified, call munmap to free
*/

void	free_chunk(void **bin, t_chunk *c, t_chunk *n)
{
	int		val;

	val = munmap(c, META_SIZE + OFFSET + c->size);
	DEBUG_LOG("Munmap block %p: %d\n", (void*)c, val);
	*bin = n;
}

/*
** munmap bin if all chunks unused
*/

void	find_free_bins(void **bin)
{
	t_chunk	*c;
	t_chunk	*n;
	int		in_use;

	c = *(t_chunk**)bin;
	while (c)
	{
		n = c->next;
		if (!(c->metadata & ALLOCED) && (!n || !(n->metadata & BLOCK)))
		{
			in_use = 0;
			while (n && !(n->metadata & BLOCK))
			{
				if (n->metadata & ALLOCED)
				{
					in_use = 1;
					break ;
				}
				n = n->next;
			}
			if (!in_use && (c->metadata & BLOCK))
				free_chunk(bin, c, n);
		}
		c = n;
	}
}

/*
** Iterate over given bin and combine consecutive free chunks,
** munmap bins if unused
*/

void	coalesce_bin(void **bin)
{
	t_chunk	*n;
	t_chunk	*c;

	c = *(t_chunk**)bin;
	while (c)
	{
		n = c->next;
		while (c && !(c->metadata & ALLOCED) && n && !(n->metadata & ALLOCED))
		{
			DEBUG_LOG("Combining chunks %p, %p\n", (void*)c, (void*)n);
			c->size += META_SIZE + OFFSET + n->size;
			c->next = n->next;
			n = n->next;
		}
		c = n;
	}
	find_free_bins(bin);
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
	if (!(chunk->metadata & LARGE_BIN))
	{
		bin = IS_TINY(chunk->size) ? &g_bins.tiny_bin : &g_bins.small_bin;
		coalesce_bin(bin);
	}
	else
		free_large_bin(chunk);
}
