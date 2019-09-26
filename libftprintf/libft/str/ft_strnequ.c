/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:10:53 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:30:04 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_strnequ
** Description Lexicographical comparison between s1 and s2 up to n characters
** or until a ’\0’ is reached. If the 2 strings are identical,
** the function returns 1, or 0 otherwise.
** Param. #1 The first string to be compared.
** Param. #2 The second string to be compared.
** Param. #3 The maximum number of characters to be compared.
** Return value 1 or 0 according to if the 2 strings are identical or not.
** Libc functions None.
*/

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	return (s1 && s2) ? ft_strncmp(s1, s2, n) == 0 : 0;
}
