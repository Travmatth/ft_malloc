/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safeatoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:15:32 by tmatthew          #+#    #+#             */
/*   Updated: 2019/04/26 15:17:01 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Traditional atoi function returns 0 on error, which introduces the possibilty
** that invalid strings may be confused for "0"
*/

int		ft_safeatoi(char *num, int *number)
{
	int		nbr;

	nbr = ft_atoi(num);
	if (!nbr && ft_strcmp("0", num))
		return (-1);
	*number = nbr;
	return (1);
}
