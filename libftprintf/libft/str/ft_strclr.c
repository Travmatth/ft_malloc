/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:21:08 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:35 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_strclr
**
** Description Sets every character of the string to the value ’\0’.
** Param. #1 The string that needs to be cleared.
** Return value None.
** Libc functions None.
*/

void	ft_strclr(char *s)
{
	if (!s || !*s)
		return ;
	while (*s)
		*s++ = '\0';
}
