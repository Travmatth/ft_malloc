/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:46:48 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/07 17:31:54 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_buf	*ft_bufappend(t_buf *b, void *new, size_t added_size)
{
	if (!b)
		return (ft_bufnew(new, added_size, added_size));
	while (b->current + added_size >= b->total)
		ft_bufresize(b);
	ft_memcpy((void*)((char*)b->buf + b->current), new, added_size);
	b->current += added_size;
	return (b);
}
