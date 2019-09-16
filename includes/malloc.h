/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 07:17:23 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/16 15:29:35 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

# define PAGE_SIZE 4000
# define IS_TINY (x) (x < 1000)
# define IS_SMALL (x) (x >= 1000)
# define IS_LARGE (x) (x >= PAGE_SIZE)

extern void	*g_tiny_bin;
extern void	*g_small_bin;
extern void	*g_large_bin;
extern void	*g_free_bin;

void	*malloc(size_t size) __attribute__((visibility("default")));
void	*realloc(void *ptr, size_t size) __attribute__((visibility("default")));
void	free(void *ptr) __attribute__((visibility("default")));

#endif
