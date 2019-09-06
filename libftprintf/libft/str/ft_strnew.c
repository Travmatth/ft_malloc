/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:13:25 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:22 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_strnew
** Description Allocates (with malloc(3)) and returns a “fresh” string ending
** with ’\0’. Each character of the string is initialized at
** ’\0’. If the allocation fails the function returns NULL.
** Param. #1 The size of the string to be allocated.
** Return value The string allocated and initialized to 0.
** Libc functions malloc(3)
*/

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char*)ft_memalloc(size + 1)))
		return (NULL);
	return (new);
}
