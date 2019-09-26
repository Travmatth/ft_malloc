/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:09:01 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:41 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_strequ
** Description Lexicographical comparison between s1 and s2. If the 2
** strings are identical the function returns 1, or 0 otherwise.
** Param. #1 The first string to be compared.
** Param. #2 The second string to be compared.
** Return value 1 or 0 according to if the 2 strings are identical or not.
** Libc functions None.
*/

int		ft_strequ(char const *s1, char const *s2)
{
	return (s1 && s2) ? ft_strcmp(s1, s2) == 0 : 0;
}
