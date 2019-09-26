/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:00:24 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:30:08 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_strmapi
** Description Applies the function f to each character of the string passed
** as argument by giving its index as first argument to create a
** “fresh” new string (with malloc(3)) resulting from the successive
** applications of f.
** Param. #1 The string to map.
** Param. #2 The function to apply to each character of s and its index.
** Return value The “fresh” string created from the successive applications of
** f.
** Libc functions malloc(3)
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*new;

	if (!s || !f || !(new = (char*)ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i += 1;
	}
	return (new);
}
