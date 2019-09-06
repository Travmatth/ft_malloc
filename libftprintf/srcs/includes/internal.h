/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:43:32 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/26 14:22:08 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "conversions.h"

typedef struct		s_kwcolor
{
	char			*kw_name;
	char			*code;
}					t_kwcolor;

typedef struct		s_print
{
	char			*str;
	size_t			size;
}					t_print;

typedef union		u_wchar
{
	wint_t			chr;
	char			byte[sizeof(wchar_t)];
}					t_wchar;

extern t_kwcolor	g_colortab[];

void				add_color_codes(t_fmt *fmt);
int					parse_h(t_fmt *spec, va_list ap, char **fmt);
int					parse_l(t_fmt *spec, va_list ap, char **fmt);
int					parse_j(t_fmt *spec, va_list ap, char **fmt);
int					parse_z(t_fmt *spec, va_list ap, char **fmt);
int					parse_t(t_fmt *spec, va_list ap, char **fmt);
int					valid_param(char *fmt);
t_fmt				*make_spec(t_state *state);
int					parse_cnv(t_fmt *spec, char **fmt, va_list ap);
int					parse(t_state *state
						, char *fmt
						, va_list ap
						, unsigned int depth);
int					vfmt_buffer(int yield(t_buf *b, void *p)
							, void *pl
							, char *fmt
							, va_list ap);
#endif
