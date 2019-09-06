/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_czero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:06:00 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/01 17:10:59 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_czero(void *ptr, char c, size_t len)
{
	size_t	i;

	if (!(ptr && c && len))
		return ;
	i = 0;
	while (i < len)
		((char*)ptr)[i++] = c;
}
