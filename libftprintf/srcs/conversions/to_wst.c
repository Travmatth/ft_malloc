/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_wst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:31:13 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 16:05:55 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/conversions.h"

void			to_wst(t_fmt *fmt)
{
	if (!fmt->type.wide_char)
		fmt->type.str = ft_strdup("(null)");
	else
		fmt->type.str = ft_wstr_to_str(fmt->type.wide_char);
	ftprintf_format_str(fmt);
}
