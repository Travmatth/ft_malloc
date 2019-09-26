/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:38:02 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:30:09 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_strmap
** Description Applies the function f to each character of the string given
** as argument to create a “fresh” new string (with malloc(3))
** resulting from the successive applications of f.
** Param. #1 The string to map.
** Param. #2 The function to apply to each character of s.
** Return value The “fresh” str created from the successive applications of f.
** Libc functions malloc(3)
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	if (!s || !f)
		return (NULL);
	if (!(new = (char*)ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = f(s[i]);
		i += 1;
	}
	return (new);
}
