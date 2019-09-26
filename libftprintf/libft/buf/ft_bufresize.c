/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufresize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:07:57 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/07 15:19:56 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_buf	*ft_bufresize(t_buf *b)
{
	void	*tmp;

	if (!b || !(tmp = ft_memalloc(b->total * 2)))
		return (NULL);
	b->total *= 2;
	ft_memcpy(tmp, b->buf, b->current);
	ft_strdel((char**)&(b->buf));
	b->buf = tmp;
	return (b);
}
