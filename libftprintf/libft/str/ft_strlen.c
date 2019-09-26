/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:10:01 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:30:06 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_strlen -- find length of string
**
** DESCRIPTION
** The ft_strlen() function computes the length of the string s.  The strnlen()
** function attempts to compute the length of s, but never scans beyond the
** first maxlen bytes of s.
**
** RETURN VALUES
** The ft_strlen() function returns the number of characters that precede the
** terminating NUL character.  The strnlen() function returns either the
** same result as ft_strlen() or maxlen, whichever is smaller.
*/

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s++)
		size += 1;
	return (size);
}
