/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:21:34 by tmatthew          #+#    #+#             */
/*   Updated: 2018/10/09 21:42:45 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/internal.h"

t_kwcolor g_colortab[] = {
	{"{red}", "\033[31m"},
	{"{bred}", "\033[31;1m"},
	{"{green}", "\033[32m"},
	{"{bgreen}", "\033[32;1m"},
	{"{yellow}", "\033[33m"},
	{"{byellow}", "\033[33;1m"},
	{"{blue}", "\033[34m"},
	{"{bblue}", "\033[34;1m"},
	{"{purple}", "\033[35m"},
	{"{bpurple}", "\033[35;1m"},
	{"{cyan}", "\033[36m"},
	{"{bcyan}", "\033[36;1m"},
	{"{black}", "\033[30m"},
	{"{bblack}", "\033[30;1m"},
	{"{white}", "\033[37m"},
	{"{bwhite}", "\033[37;1m"},
	{"{b_red}", "\033[41m"},
	{"{b_bred}", "\033[41;1m"},
	{"{b_green}", "\033[42m"},
	{"{b_bgreen}", "\033[42;1m"},
	{"{b_yellow}", "\033[43m"},
	{"{b_byellow}", "\033[43;1m"},
	{"{b_blue}", "\033[44m"},
	{"{b_bblue}", "\033[44;1m"},
	{"{b_purple}", "\033[45m"},
	{"{b_bpurple}", "\033[45;1m"},
	{"{b_cyan}", "\033[46m"},
	{"{b_bcyan}", "\033[46;1m"},
	{"{b_black}", "\033[40m"},
	{"{b_bblack}", "\033[40;1m"},
	{"{b_white}", "\033[47m"},
	{"{b_bwhite}", "\033[47;1m"},
	{"{eoc}", "\033[0m"}
};

void	add_color_codes(t_fmt *fmt)
{
	int		i;
	char	*tmp;

	if ((!fmt->out || fmt->len.out <= 1
		|| ft_count_char(fmt->out, '{') < 1
		|| ft_count_char(fmt->out, '}') < 1))
		return ;
	i = -1;
	while (++i < 33)
	{
		if (!(tmp = ft_swap_all(fmt->out
								, g_colortab[i].kw_name
								, g_colortab[i].code)))
			continue ;
		if (tmp != fmt->out)
		{
			ft_strdel(&fmt->out);
			fmt->out = tmp;
		}
	}
	fmt->len.out = LEN(fmt->out, 0);
}
