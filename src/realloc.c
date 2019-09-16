/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 06:48:33 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/16 14:39:45 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void __attribute__((visibility("default"))) *realloc(void *pointer, size_t size)
{
    (void)pointer;
    (void)size;
	return (NULL);
}
