/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:36:06 by tmatthew          #+#    #+#             */
/*   Updated: 2019/10/02 17:20:53 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/internal.h"

/*
** Print information on current allocations
** TINY : 0xA0000
** 0xA0020 - 0xA004A : 42 bytes
** 0xA006A - 0xA00BE : 84 bytes
** SMALL : 0xAD000
** 0xAD020 - 0xADEAD : 3725 bytes
** LARGE : 0xB0000
** 0xB0020 - 0xBBEEF : 48847 bytes
** Total : 52698 bytes
*/

size_t	print_allocations(void *bin)
{
	size_t	bytes;
	t_chunk	*chunk;
	void	*ptr;

	bytes = 0;
	chunk = (t_chunk*)bin;
	while (chunk)
	{
		if (chunk->metadata & ALLOCED)
		{
			bytes += chunk->size;
			ptr = GET_MEM_POINTER(chunk);
			nomalloc_log(STDOUT, "0x%P - 0x%P : %zu bytes\n"
						, ptr
						, ((void*)((char*)ptr + chunk->size))
						, chunk->size);
		}
		chunk = chunk->next;
	}
	return (bytes);
}

void	show_alloc_mem(void)
{
	size_t	total;

	nomalloc_log(STDOUT, "TINY: 0x%P\n", g_bins.tiny_bin);
	total = print_allocations(g_bins.tiny_bin);
	nomalloc_log(STDOUT, "SMALL: 0x%P\n", g_bins.small_bin);
	total += print_allocations(g_bins.small_bin);
	nomalloc_log(STDOUT, "LARGE: 0x%P\n", g_bins.large_bin);
	total += print_allocations(g_bins.large_bin);
	nomalloc_log(STDOUT, "Total : %zu bytes\n", total);
}
