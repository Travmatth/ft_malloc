/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striterl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:24:12 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:46 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_striterl(void (*f)(void *elem, size_t i, int *stop), char *str)
{
	size_t	i;
	int		stop;

	if (!(f && str))
		return (NULL);
	i = 0;
	stop = 0;
	while (!stop && str[i++])
		f(&(str[i]), i, &stop);
	return (str);
}
