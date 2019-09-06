/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_delim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:40:32 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:33 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_next_delim
** Description finds the next occurence of character delim in the string.
** Param. #1 The string to search.
** Param. #2 The delimiter character.
** Return value a char* to the next occurence of character delim in string
** or NULL if delim not found
*/

char	*ft_next_delim(char const *string, char delim)
{
	char	*next;

	next = (char*)string;
	while (*next)
	{
		if (*next == delim)
			return (next);
		next += 1;
	}
	return (next);
}
