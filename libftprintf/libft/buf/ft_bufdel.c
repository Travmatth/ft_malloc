/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 21:33:40 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/31 15:40:30 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bufdel(t_buf **b)
{
	char	*buffer_str;

	if (!b || !*b)
		return ;
	buffer_str = (char*)((*b)->buf);
	ft_freeall(2, b, &buffer_str);
}
