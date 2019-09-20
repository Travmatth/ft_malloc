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

#include "../includes/malloc.h"

/*
** Iterate over given bin and combine consecutive free chunks
*/

void	coalesce_bin(void *bin)
{
	(void)bin;
}

/*
** Mark given pointer as a free chunk
*/

void	free(void *pointer)
{
	t_chunk	*chunk;

	if (pointer == NULL || (size_t)pointer % 8)
		return ;
	DEBUG_LOG("Freeing pointer: %p\n", pointer);
	chunk = get_chunk_pointer(pointer);
	if (!(chunk->metadata & FREE))
	{
		DEBUG_LOG("Error: Attempt to free unallocated chunk %p\n", pointer);
		// raise(SIGSEGV);
	}
	chunk->metadata &= ~FREE;
	coalesce_bin(g_bins.tiny_bin);
	coalesce_bin(g_bins.small_bin);
	coalesce_bin(g_bins.large_bin);
}
