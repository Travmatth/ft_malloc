/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:09:51 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:23 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** memset -- fill a byte string with a byte value
**
** DESCRIPTION
** The memset() function writes len bytes of value c (converted to an
** unsigned char) to the string b.
**
** RETURN VALUES
** The memset() function returns its first argument.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*b_ptr;

	i = 0;
	b_ptr = b;
	while (i < len)
		*(b_ptr + i++) = c;
	return (b);
}
