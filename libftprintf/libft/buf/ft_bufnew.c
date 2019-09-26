/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:29:16 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/07 18:52:42 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_buf	*ft_bufnew(void *data, size_t current, size_t total)
{
	t_buf	*buf;

	if (!data || !(buf = ft_memalloc(sizeof(t_buf))))
		return (NULL);
	buf->buf = data;
	buf->current = current;
	buf->total = total;
	return (buf);
}
