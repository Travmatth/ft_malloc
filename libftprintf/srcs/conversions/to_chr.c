/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_chr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:43:32 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 16:05:32 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/conversions.h"

void	to_chr(t_fmt *fmt)
{
	fmt->type.str = (char*)ft_memdup((void*)&fmt->type.signed_char
					, sizeof(char));
	fmt->out = fmt->type.str;
	fmt->len.out = 1;
	ftprintf_format_chr(fmt);
}
