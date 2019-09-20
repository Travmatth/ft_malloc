/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 06:48:33 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/20 15:46:15 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static	int		within_bounds(
	size_t *n, int mover, void **str1_tmp, const void **str2)
{
	return ((*n -= mover)
		&& (*str1_tmp = (char*)*str1_tmp + mover)
		&& (*str2 = (char*)*str2 + mover));
}

static	void	*ft_memcpy_eng(void *str1, const void *str2, size_t n)
{
	int		mover;
	void	*str1_tmp;

	mover = 0;
	str1_tmp = str1;
	while (n > 0 && within_bounds(&n, mover, &str1_tmp, &str2))
	{
		mover = 0;
		if (n >= 8)
		{
			*(long int*)str1_tmp = *(long int*)str2;
			mover = sizeof(long int);
		}
		else if (n >= 4)
		{
			*(int*)str1_tmp = *(int*)str2;
			mover = sizeof(int);
		}
		else
		{
			*(char*)str1_tmp = *(char*)str2;
			mover = sizeof(char);
		}
	}
	return (str1);
}

void			*ft_fast_memcpy(void *str1, const void *str2, size_t n)
{
	if (!str1 && !str2 && n == 0)
		return (ft_memcpy_eng(str1, str2, n));
	if (!str1)
		*(long int*)str1 = *(long int*)str1;
	if (!str2)
		*(long int*)str2 = *(long int*)str2;
	return (ft_memcpy_eng(str1, str2, n));
}

void	*realloc(void *pointer, size_t size)
{
	t_chunk	*old;
	t_chunk	*new;
	size_t	new_size;

	if ((size_t)pointer % 8)
	{
		DEBUG_LOG("Realloc attempted on misaligned pointer: %p\n", pointer);
		return (NULL);
	}
	else if (pointer == NULL)
	{
		DEBUG_LOG("Realloc returning new pointer of size: %zu\n", size);
		return (malloc(size));
	}
	old = get_chunk_pointer(pointer);
	new_size = MIN(size, old->size);
	if ((new = malloc(size)) == NULL)
	{
		DEBUG_LOG("Realloc failed to allocate pointer of size: %zu\n", size);
		return (NULL);
	}
	ft_fast_memcpy((void*)(new + 1), pointer, new_size);
	free(pointer);
	DEBUG_LOG("Realloc moved %zu bytes from %p to pointer %p of size: %zu\n"
		, new_size
		, pointer
		, (void*)(new + 1)
		, size);
	return ((void*)(new + 1));
}
