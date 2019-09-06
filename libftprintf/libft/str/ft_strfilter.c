/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:30:13 by tmatthew          #+#    #+#             */
/*   Updated: 2018/10/29 18:56:51 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	count_chars(int (*f)(char elem, size_t i, char *str, int *stop)
					, char *str)
{
	size_t	i;
	size_t	j;
	int		stop;

	i = 0;
	j = 0;
	stop = 0;
	while (str[j])
	{
		i += f(str[j], j, str, &stop) ? 1 : 0;
		j += 1;
	}
	return (i);
}

char			*ft_strfilter(
					int (*f)(char elem, size_t i, char *str, int *stop)
					, char *str)
{
	char	*final;
	size_t	i;
	size_t	j;
	int		stop;

	if (!(f && str))
		return (NULL);
	i = 0;
	j = 0;
	stop = 0;
	final = NULL;
	i = count_chars(f, str);
	if (!(final = (char*)ft_strnew(i)))
		return (NULL);
	i = 0;
	while (!stop && str[i])
	{
		if (f(str[i], i, str, &stop))
		{
			final[j] = str[i];
			j += 1;
		}
		i += 1;
	}
	return (final);
}
