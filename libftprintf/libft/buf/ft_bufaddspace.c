/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:46:48 by tmatthew          #+#    #+#             */
/*   Updated: 2018/07/21 18:37:56 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** expand buf by given size, free previous buf
*/

t_buf		*ft_bufaddspace(t_buf *b, size_t i)
{
	char	*tmp;

	if (!b)
		return (NULL);
	if (!i)
		return (b);
	tmp = ft_memalloc(b->total + i);
	ft_memcpy(tmp, b->buf, b->current);
	free(b->buf);
	b->buf = tmp;
	b->total += i;
	return (b);
}
