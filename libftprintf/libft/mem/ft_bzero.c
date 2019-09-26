/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:35:09 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:05 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** bzero -- write zeroes to a byte string
** DESCRIPTION
** The bzero() function writes n zeroed bytes to the string s.
** If n is zero, bzero() does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s_ptr;

	i = 0;
	s_ptr = (char*)s;
	while (i < n)
		*(s_ptr + i++) = 0;
}
