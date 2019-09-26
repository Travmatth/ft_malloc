/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:55:40 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:16 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_memdel
** Description Takes as a parameter the address of a memory area that needs
** to be freed with free(3), then puts the pointer to NULL.
** Param. #1 A pointer’s address that needs its memory freed and set to
** NULL.
** Return value None.
** Libc functions free(3).
*/

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	if (*ap != 0)
		free(*ap);
	*ap = 0;
}
