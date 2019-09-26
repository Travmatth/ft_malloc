/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:43:37 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:54 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_strsub
** Description Allocates (with malloc(3)) and returns a “fresh” substring
** from the string given as argument. The substring begins at
** indexstart and is of size len. If start and len aren’t refering
** to a valid substring, the behavior is undefined. If the
** allocation fails, the function returns NULL.
** Param. #1 The string from which create the substring.
** Param. #2 The start index of the substring.
** Param. #3 The size of the substring.
** Return value The substring.
** Libc functions malloc(3)
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || !(sub = (char*)ft_strnew(len)))
		return (NULL);
	return (ft_memcpy((void*)sub, (void*)(s + start), len));
}
