/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:43:32 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 16:25:22 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H

# include "definitions.h"

# define SPECIFIERS "sSpdDioOuUxXcCeEfFgGaAnt"
# define PREC_SET(s) (s->precision == I_MIN)
# define IS_ZERO(s) (s->len.out ==1 && *s->out == '0')
# define IS_PLUSMINUS(s) (GET(s->flags, '+') || GET(s->flags, '-'))
# define IS_HH(s) (s->len.modifiers[0] == 'h' && s->len.modifiers[1] == 'h')
# define IS_H(s) (s->len.modifiers[0] == 'h' && !s->len.modifiers[1])
# define IS_L(s) (s->len.modifiers[0] == 'l' && !s->len.modifiers[1])
# define IS_LL(s) (s->len.modifiers[0] == 'l' && s->len.modifiers[1] == 'l')
# define IS_J(s) (s->len.modifiers[0] == 'j' && !s->len.modifiers[1])
# define IS_Z(s) (s->len.modifiers[0] == 'z' && !s->len.modifiers[1])
# define IS_T(s) (s->len.modifiers[0] == 't' && !s->len.modifiers[1])

typedef void				(*t_cnv)(t_fmt *fmt);

typedef	struct	s_f_cnv
{
	char		cnv;
	t_cnv		f;
}				t_f_cnv;

size_t			fmt_str_unchanged(t_fmt *fmt, size_t orig_len);
void			handle_ll(t_val type, t_fmt *fmt, const char *lookup);
void			handle_hh(t_val type, t_fmt *fmt, const char *lookup);
void			handle_h(t_val type, t_fmt *fmt, const char *lookup);
void			handle_l(t_val type, t_fmt *fmt, const char *lookup);
void			handle_d(t_val type, t_fmt *fmt, const char *lookup);
void			to_lit(t_fmt *fmt);
void			to_str(t_fmt *fmt);
void			to_dec(t_fmt *fmt);
void			to_uns(t_fmt *fmt);
void			to_oct(t_fmt *fmt);
void			to_hex(t_fmt *fmt);
void			to_ptr(t_fmt *fmt);
void			to_chr(t_fmt *fmt);
void			to_flo(t_fmt *fmt);
void			to_wch(t_fmt *fmt);
void			to_wst(t_fmt *fmt);
void			ftprintf_format_nbr(t_fmt *fmt);
void			ftprintf_format_chr(t_fmt *fmt);
size_t			ftprintf_format_str(t_fmt *fmt);
t_cnv			*get_cnv_table(void);
t_cnv			ftprintf_register_cnv(unsigned code, t_cnv *f);
size_t			set_alternate(t_fmt *fmt);
size_t			get_prefix(t_fmt *fmt);
void			set_zero_padding(t_fmt *fmt
						, size_t *zero_len
						, size_t *width_len
						, size_t *prefix_len);
void			set_prefix(t_fmt *fmt
						, size_t *zero_len
						, size_t *width_len
						, size_t *prefix_len);
#endif
