/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 07:17:23 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/25 22:10:54 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# define MIN(x, y) ((x) < (y) ? (x) : (y))

/*
** stddef.h - NULL, alignof, max_align_t
** unistd.h - mmap
** sys/mman.h - PROT_READ, PROT_WRITE, MAP_ANON, MAP_PRIVATE
** errno - errno
** stdalign - alignof, max_align_t
*/

# include <stddef.h>
# include <unistd.h>
# include <sys/mman.h>
# include <errno.h>
# include <stdalign.h>
# include "../libftprintf/srcs/includes/ft_printf.h"

/*
** Debug statements used when compiled with __DEBUG__ variable defined
*/

# ifdef __DEBUG__
#  include <stdio.h>
#  define DEBUG_LOG(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
#  define DEBUG_PRINT(str) fprintf(stderr, str)
# else
#  define DEBUG_LOG(fmt, ...) do {} while (0)
#  define DEBUG_PRINT(str) do {} while (0)
# endif

/*
** Masks used to interpret block settings
*/

enum	e_block_flags {
	ALLOCED = (1u << 0),
	BLOCK = (1u << 1),
};

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
** Chunk struct used to store information about the mmapped memory
*/

typedef struct		s_chunk {
	struct s_chunk	*next;
	size_t			size;
	unsigned		metadata;
}					t_chunk;

/*
** Bins used to reference mmapped sections of memory
** tiny_bin: allocations < 1kb
** small_bin: allocations >= 1kb && < 4kb
** large_bin: allocations > 4kb
*/

# define MB 1000000
# define TINY_SIZE (2 * MB)
# define SMALL_SIZE (16 * MB)
# define IS_TINY(x) (x < 500)
# define IS_SMALL(x) (x >= 500)
# define IS_LARGE(x) (x >= PAGE_SIZE)

/*
** Macros used for calculating chunk sizes
*/

# define META_SIZE (sizeof(t_chunk))
# define PAGE_SIZE ((size_t)getpagesize())
# define OFFSET (alignof(max_align_t) - sizeof(t_chunk)) % alignof(max_align_t)

/*
** Macros used for allocations
*/

# define MMAP_PROTECTIONS (PROT_READ | PROT_WRITE)
# define MMAP_FLAGS (MAP_ANON | MAP_PRIVATE)

/*
** Macros used to calculate address of chunk & pointer
*/

# define GET_MEM_POINTER(x) ((void*)((char*)(t_chunk*)(x + 1) + OFFSET))
# define GET_CHUNK_POINTER(x) ((t_chunk*)((char*)(((t_chunk*)x) - 1) - OFFSET))

/*
** Internal functions
*/

t_chunk	*request_space(t_chunk *last, size_t size);
t_chunk	*next_free_chunk(t_chunk **last, size_t size, void *bin);

/*
** Exported functions
*/

void	show_alloc_mem();
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	free(void *ptr);
#endif
