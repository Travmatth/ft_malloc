/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:29:12 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:44 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Description Allocates (with malloc(3)) and returns a “fresh” string ending
** with ’\0’, result of the concatenation of s1 and s2. If
** the allocation fails the function returns NULL.
** Param. #1 The prefix string.
** Param. #2 The suffix string.
** Return value The “fresh” string result of the concatenation of the 2 strings.
** Libc functions malloc(3)
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*u_str;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(u_str = ft_strnew((s1_len + s2_len))))
		return (NULL);
	while (++i < s1_len)
		*(u_str + i) = *(s1 + i);
	while (++j < s2_len)
		*(u_str + i++) = *(s2 + j);
	return (u_str);
}
