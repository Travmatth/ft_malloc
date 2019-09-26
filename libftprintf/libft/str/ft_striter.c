/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:52:37 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:42 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_striter
** Description Applies the function f to each character of the string passed
** as argument. Each character is passed by address to f to be
** modified if necessary.
** Param. #1 The string to iterate.
** Param. #2 The function to apply to each character of s.
** Return value None.
** Libc functions None.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
		while (*s)
			f(s++);
}
