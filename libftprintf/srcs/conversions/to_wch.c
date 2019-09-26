/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_wch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:31:13 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 16:05:55 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/conversions.h"

void		to_wch(t_fmt *fmt)
{
	char	string[4];

	ft_bzero(string, 4);
	if (!fmt->type.wide_int)
		fmt->type.str = ft_strdup("(null)");
	else
	{
		ft_str_to_unicode(fmt->type.wide_int, string);
		fmt->type.str = ft_strdup(string);
	}
	ftprintf_format_str(fmt);
}
