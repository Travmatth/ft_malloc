/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 07:17:23 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/17 16:28:38 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

/*
** stddef.h - NULL
** unistd.h - mmap
*/

# include <stddef.h>
# include <unistd.h>

/*
** Breakpoints used to determine which bin to procure allocated memory from
*/

# define PAGE_SIZE 4000
# define IS_TINY(x) (x < 1000)
# define IS_SMALL(x) (x >= 1000)
# define IS_LARGE(x) (x >= PAGE_SIZE)

/*
** Debug statements used when compiled with __DEBUG__ variable defined
*/

#ifdef __DEBUG__
# include <stdio.h>
# define DEBUG_LOG(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
# define DEBUG_PRINT(str) fprintf(stderr, str)
#else
# define DEBUG_(fmt, ...) do {} while (0)
# define DEBUG_PRINT(str) do {} while (0)
#endif

/*
** Chunk struct used to store information about the mmapped memory
*/

typedef struct		s_chunk {
    struct s_chunk	*prev;
    char			*avail;
    char			*limit;
}					t_chunk;

/*
** Bins used to reference mmapped sections of memory
** g_tiny_bin: allocations < 1kb
** g_small_bin: allocations >= 1kb && < 4kb
** g_large_bin: allocations > 4kb
*/

extern t_chunk	*g_tiny_bin;
extern t_chunk	*g_small_bin;
extern t_chunk	*g_large_bin;
extern t_chunk	*g_free_bin;

void	*malloc(size_t size) __attribute__((visibility("default")));
void	*realloc(void *ptr, size_t size) __attribute__((visibility("default")));
void	free(void *ptr) __attribute__((visibility("default")));

#endif
