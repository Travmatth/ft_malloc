/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_lit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:43:32 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 16:05:55 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/conversions.h"

void	to_lit(t_fmt *fmt)
{
	fmt->type.str = ft_strdup("%");
	ftprintf_format_str(fmt);
}
