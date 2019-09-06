/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 17:22:37 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 16:23:05 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/conversions.h"

t_f_cnv g_cnv_lst[] =
{
	{'d', &to_dec},
	{'D', &to_dec},
	{'i', &to_dec},
	{'p', &to_ptr},
	{'o', &to_oct},
	{'O', &to_oct},
	{'x', &to_hex},
	{'X', &to_hex},
	{'u', &to_uns},
	{'U', &to_uns},
	{'s', &to_str},
	{'S', &to_wst},
	{'c', &to_chr},
	{'C', &to_wch},
	{'f', &to_flo},
	{'%', &to_lit}
};

/*
** get_cnv_table
** returns the conversion table used to map conversions to their handlers
*/

t_cnv	*get_cnv_table(void)
{
	unsigned		i;
	static t_cnv	conversions[128];
	static int		init;

	if (!init)
	{
		init = 1;
		i = 0;
		while (i < 16)
		{
			conversions[(unsigned)g_cnv_lst[i].cnv] = g_cnv_lst[i].f;
			i += 1;
		}
	}
	return (conversions);
}

/*
** ftprintf_register_cnv
** registers custom conversion specifiers for the given ascii character
*/

t_cnv	ftprintf_register_cnv(unsigned code, t_cnv *f)
{
	t_cnv		*conversions;
	t_cnv		ret;

	conversions = get_cnv_table();
	ret = conversions[code];
	conversions[code] = *f;
	return (ret);
}
