/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:06:41 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:36 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_strdel
** Description Takes as a parameter the address of a string that need to be
** freed with free(3), then sets its pointer to NULL.
** Param. #1 The string’s address that needs to be freed and its pointer set
** to NULL.
** Return value None.
** Libc functions Free(3).
*/

void	ft_strdel(char **as)
{
	if (!as || !*as)
		return ;
	free(*as);
	*as = 0;
}
