/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:31:13 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 16:05:55 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/conversions.h"

void	to_str(t_fmt *fmt)
{
	if (!fmt->type.str)
		fmt->type.str = ft_strdup("(null)");
	ftprintf_format_str(fmt);
}
