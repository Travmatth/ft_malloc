/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:08:27 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:32 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** strcat, strncat -- concatenate strings
**
** DESCRIPTION
** The strcat() and strncat() functions append a copy of the null-terminated
** string s2 to the end of the null-terminated string s1, then add a termi-
** nating `\0'.  The string s1 must have sufficient space to hold the
** result.
**
** The source and destination strings should not overlap, as the behavior is
** undefined.
**
** RETURN VALUES
** The strcat() and strncat() functions return the pointer s1.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i_s1;
	size_t	i_s2;

	i_s1 = ft_strlen(s1);
	i_s2 = ft_strlen(s2);
	ft_memcpy((void*)(s1 + i_s1), (void*)s2, i_s2);
	s1[i_s1 + i_s2] = '\0';
	return (s1);
}
