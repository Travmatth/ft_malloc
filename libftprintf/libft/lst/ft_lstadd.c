/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:03:08 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:39 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_lstadd
** Description Adds the element new at the beginning of the list.
** Param. #1 The address of a pointer to the first link of a list.
** Param. #2 The link to add at the beginning of the list.
** Return value None.
** Libc functions None.
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	else if (!*alst)
		*alst = new;
	else
	{
		new->next = *alst;
		*alst = new;
	}
}
