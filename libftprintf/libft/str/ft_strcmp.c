/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:28:14 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:37 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** strcmp, strncmp -- compare strings
**
** DESCRIPTION
** The strcmp() and strncmp() functions lexicographically compare the null-
** terminated strings s1 and s2.
**
** The strncmp() function compares not more than n characters.  Because
** strncmp() is designed for comparing strings rather than binary data,
** characters that appear after a `\0' character are not compared.
**
** RETURN VALUES
** The strcmp() and strncmp() functions return an integer greater than,
** equal to, or less than 0, according as the string s1 is greater than,
** equal to, or less than the string s2.  The comparison is done using
** unsigned characters, so that `\200' is greater than `\0'.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1 += 1;
		s2 += 1;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
