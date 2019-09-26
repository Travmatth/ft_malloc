/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:28:50 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:30:00 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_strsplit
** Description Allocates (with malloc(3)) and returns an array of “fresh”
** strings (all ending with ’\0’, including the array itself) obtained
** by spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL. Example
** : ft_strsplit("*hello*fellow***students*", ’*’) returns
** the array ["hello", "fellow", "students"].
** Param. #1 The string to split.
** Param. #2 The delimiter character.
** Return value The array of “fresh” strings result of the split.
** Libc functions malloc(3), free(3)
*/

char	**ft_strsplit(char const *string, char delim)
{
	char	**array;
	size_t	len_til_delim;
	size_t	current;
	size_t	word_count;

	if (!string)
		return (NULL);
	word_count = ft_count_by_delim(string, delim);
	if (!(array = (char**)ft_memalloc(sizeof(char**) * (word_count + 1))))
		return (NULL);
	current = -1;
	while (++current < word_count)
	{
		string = ft_skip_delim((char*)string, delim);
		len_til_delim = ft_next_delim(string, delim) - string;
		if (len_til_delim)
		{
			array[current] = ft_strnew(len_til_delim + 1);
			ft_memcpy(array[current], string, len_til_delim);
		}
		string += len_til_delim;
	}
	return (array);
}
