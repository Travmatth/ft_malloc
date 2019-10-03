/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 07:17:23 by tmatthew          #+#    #+#             */
/*   Updated: 2019/10/03 15:28:32 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_INTERNAL_H
# define MALLOC_INTERNAL_H

/*
** stdarg.h - va_list
** stddef.h - NULL, alignof, max_align_t
** unistd.h - mmap, getpagesize
** sys/mman.h - PROT_READ, PROT_WRITE, MAP_ANON, MAP_PRIVATE
** errno.h - errno
** stdalign.h - alignof, max_align_t
** stdint.h - intmax_t, uintmax_t
*/

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <sys/mman.h>
# include <errno.h>
# include <stdalign.h>
# include <stdint.h>

/*
** Macros for utils.c
*/

# define ULL unsigned long long
# define NOT_LONG_BOUNDARY(X) (((long)X & (sizeof (long) - 1)))
# define UNALIGNED(X, Y) (NOT_LONG_BOUNDARY(X) | NOT_LONG_BOUNDARY(Y))
# define BIGBLOCKSIZE (sizeof (long) << 2)
# define LITTLEBLOCKSIZE (sizeof (long))
# define TOO_SMALL(LEN) ((LEN) < BIGBLOCKSIZE)
# define DEC "0123456789"
# define HEX "0123456789ABCDEF"

/*
** Masks used to interpret block settings
*/

enum	e_block_flags {
	ALLOCED = (1u << 0),
	BLOCK = (1u << 1),
	TINY_BIN = (1u << 2),
	SMALL_BIN = (1u << 3),
	LARGE_BIN = (1u << 4),
};

/*
** Global variable used to store reference to memory bins
*/

typedef struct		s_bins {
	void			*tiny_bin;
	void			*small_bin;
	void			*large_bin;
}					t_bins;

extern t_bins		g_bins;

/*
** Chunk struct used to store information about the mmapped memory
*/

typedef struct		s_chunk {
	struct s_chunk	*next;
	size_t			size;
	unsigned		metadata;
}					t_chunk;

/*
** Macros used for calculating chunk sizes
*/

# define META_SIZE (sizeof(t_chunk))
# define PAGE_SIZE ((size_t)getpagesize())
# define OFFSET (alignof(max_align_t) - sizeof(t_chunk)) % alignof(max_align_t)
# define ALIGN (alignof(max_align_t))
# define ALIGNED_SIZE(x) ((x + ((alignof(max_align_t) - x) % ALIGN)))

/*
** Bins used to reference mmapped sections of memory
** tiny_bin: allocations < 1kb
** small_bin: allocations >= 1kb && < 4kb
** large_bin: allocations > 4kb
*/

# define TINY_SIZE (4 * PAGE_SIZE)
# define SMALL_SIZE (8 * PAGE_SIZE)
# define IS_TINY(x) (x < 512)
# define IS_SMALL(x) (x >= 512)
# define IS_LARGE(x) (x >= PAGE_SIZE)

/*
** Macros used for allocations
*/

# define MMAP_PROTECTIONS (PROT_READ | PROT_WRITE)
# define MMAP_FLAGS (MAP_ANON | MAP_PRIVATE)
# define CHUNK_IS_FREE(c) (!(c->metadata & ALLOCED))

/*
** Macros used to calculate address of chunk & pointer
*/

# define GET_MEM_POINTER(x) ((void*)((char*)(t_chunk*)(x + 1) + OFFSET))
# define GET_CHUNK_POINTER(x) ((t_chunk*)((char*)(((t_chunk*)x) - 1) - OFFSET))

/*
** Misc
*/

# define STDOUT 1
# define MIN(x, y) ((x) < (y) ? (x) : (y))

/*
** Internal functions
*/

size_t				ft_intmaxtoa_base(char *string
							, intmax_t nbr
							, int8_t base
							, const char *lookup);
void				*ft_memcpy(void *dst_void
							, const void *src_void
							, size_t len);
t_chunk				*request_space(t_chunk *last, size_t size);
t_chunk				*next_free_chunk(t_chunk **last, size_t size, void *bin);
int					is_chunk(t_chunk *chunk);

/*
** Exported functions
*/

void				nomalloc_log(int fd, const char *fmt, ...);
void				show_alloc_mem();
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				free(void *ptr);

/*
** Debug statements used when compiled with __DEBUG__ variable defined
*/

# ifdef __DEBUG__
#  define STDERR 2
#  define DEBUG_LOG(fmt, ...) nomalloc_log(STDERR, fmt, __VA_ARGS__)
#  define DEBUG_PRINT(str) nomalloc_log(STDERR, str)
# else
#  define DEBUG_LOG(fmt, ...) do {} while (0)
#  define DEBUG_PRINT(str) do {} while (0)
# endif

#endif
