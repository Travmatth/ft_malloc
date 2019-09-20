/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 07:17:23 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/20 14:26:48 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# define MIN(x, y) ((x) < (y) ? (x) : (y))

/*
** stddef.h - NULL
** unistd.h - mmap
** sys/mman.h - PROT_READ, PROT_WRITE, MAP_ANON, MAP_PRIVATE
*/

# include <signal.h>
# include <stddef.h>
# include <unistd.h>
# include <sys/mman.h>

/*
** Breakpoints used to determine which bin to procure allocated memory from
*/

# define PAGE_SIZE ((size_t)getpagesize())
# define IS_TINY(x) (x < 500)
# define IS_SMALL(x) (x >= 500)
# define IS_LARGE(x) (x >= PAGE_SIZE)

# define MMAP_PROTECTIONS (PROT_READ | PROT_WRITE)
# define MMAP_FLAGS (MAP_ANON | MAP_PRIVATE)

/*
** Debug statements used when compiled with __DEBUG__ variable defined
*/

#ifdef __DEBUG__
# include <stdio.h>
# define DEBUG_LOG(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
# define DEBUG_PRINT(str) fprintf(stderr, str)
#else
# define DEBUG_LOG(fmt, ...) do {} while (0)
# define DEBUG_PRINT(str) do {} while (0)
#endif

/*
** Masks used to interpret block settings
*/

enum BlockFlags {
	FREE = (1u << 0),
	ARENA = (1u << 1),
};

/*
** Chunk struct used to store information about the mmapped memory
*/

typedef struct		s_chunk {
    struct s_chunk	*next;
	size_t			size;
	char			metadata;
}					t_chunk;

# define META_SIZE (sizeof(t_chunk))

/*
** Bins used to reference mmapped sections of memory
** tiny_bin: allocations < 1kb
** small_bin: allocations >= 1kb && < 4kb
** large_bin: allocations > 4kb
*/

# define MB 1000000
# define TINY_SIZE (2 * MB)
# define SMALL_SIZE (16 * MB)

/*
** Global variable used to store reference to memory bins
*/

typedef struct	s_bins {
	void		*tiny_bin;
	void		*small_bin;
	void		*large_bin;
}				t_bins;

extern t_bins	g_bins;

/*
** Internal functions
*/

t_chunk	*get_chunk_pointer(void *pointer);
t_chunk	*request_space(t_chunk *last, size_t size);
t_chunk	*next_free_chunk(t_chunk **last, size_t size, void *bin);

/*
** Exported functions
*/

void	show_alloc_mem() __attribute__((visibility("default")));
void	*malloc(size_t size) __attribute__((visibility("default")));
void	*realloc(void *ptr, size_t size) __attribute__((visibility("default")));
void	free(void *ptr) __attribute__((visibility("default")));
#endif
