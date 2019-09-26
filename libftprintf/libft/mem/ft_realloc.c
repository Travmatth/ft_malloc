/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:49:29 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/07 15:19:56 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_realloc(void **ptr, size_t size)
{
	void	*new;

	if (!(ptr && *ptr && size) || !(new = ft_memalloc(size)))
		return (NULL);
	ft_memcpy(new, *ptr, size);
	ft_strdel((char**)ptr);
	return (new);
}
