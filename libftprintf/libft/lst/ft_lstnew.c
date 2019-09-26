/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:59:32 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:55 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_lstnew
**
** Description Allocates (with malloc(3)) and returns a “fresh” link. The
** variables content and content_size of the new link are initialized
** by copy of the parameters of the function. If the parameter
** content is nul, the variable content is initialized to
** NULL and the variable content_size is initialized to 0 even
** if the parameter content_size isn’t. The variable next is
** initialized to NULL. If the allocation fails, the function returns
** NULL.
**
** Param. #1 The content to put in the new link.
** Param. #2 The size of the content of the new link.
** Return value The new link.
** Libc functions malloc(3), free(3)
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	if (!(new->content = ft_memcpy(ft_memalloc(content_size)
									, content
									, content_size)))
		return (NULL);
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
