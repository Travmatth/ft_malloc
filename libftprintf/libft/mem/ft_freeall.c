/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:13:32 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/30 18:58:46 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_freeall
** calls ft_strdel for every param given
*/

void	ft_freeall(int total, ...)
{
	int		current;
	va_list	ap;

	if (total < 0)
		return ;
	current = -1;
	va_start(ap, total);
	while (++current < total)
		ft_strdel(va_arg(ap, char**));
	va_end(ap);
}
