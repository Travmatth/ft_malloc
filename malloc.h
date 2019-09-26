/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:42:35 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/26 14:22:58 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# ifndef _STDDEF_H
#  include <stddef.h>
# endif

/*
** Exported functions
*/

void	show_alloc_mem();
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	free(void *ptr);
#endif
