/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:11:40 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 15:18:47 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include <stdlib.h>
# include "../../libft/libft.h"

# define S_M(v, c) (c == '-' && BITSET(v, 0))
# define S_P(v, c) (c == '+' && BITSET(v, 1))
# define S_S(v, c) (c == ' ' && BITSET(v, 2))
# define S_Z(v, c) (c == '0' && BITSET(v, 3))
# define S_H(v, c) (c == '#' && BITSET(v, 4))
# define SET_1(v, c) (S_M(v, c) || S_P(v, c) || S_S(v, c))
# define SET_2(v, c) (S_Z(v, c) || S_H(v, c))
# define SET(v, c) (SET_1(v, c) || SET_2(v, c))

# define G_M(v, c) (c == '-' && BITTEST(v, 0))
# define G_P(v, c) (c == '+' && BITTEST(v, 1))
# define G_S(v, c) (c == ' ' && BITTEST(v, 2))
# define G_Z(v, c) (c == '0' && BITTEST(v, 3))
# define G_H(v, c) (c == '#' && BITTEST(v, 4))
# define GET_1(v, c) (G_M(v, c) || G_P(v, c) || G_S(v, c))
# define GET_2(v, c) (G_Z(v, c) || G_H(v, c))
# define GET(v, c) (GET_1(v, c) || GET_2(v, c))

# define SET_IS_NEG(v) (BITSET(v, 5))
# define GET_IS_NEG(v) (BITTEST(v, 5))
# define SET_IS_TEXT(v) (BITSET(v, 6))
# define GET_IS_TEXT(v) (BITTEST(v, 6))
# define SET_IS_LINK(v) (BITSET(v, 7))
# define GET_IS_LINK(v) (BITTEST(v, 7))

# define FLAG_SIZE BITNSLOTS(8)
# define SIGN_SET(x) (x & 0xf0)
# define PTR_SET(x) (x & 0xf0)

typedef	struct				s_len
{
	size_t					out;
	char					modifiers[2];
}							t_len;

typedef struct				s_fmt
{
	char					*out;
	t_val					type;
	unsigned				width;
	unsigned				arg_position;
	unsigned				precision;
	int						link;
	t_len					len;
	char					flags[FLAG_SIZE];
	char					cnv;
	char					prefix[2];
}							t_fmt;

typedef struct				s_state
{
	t_buf					*in;
	t_buf					*out;
}							t_state;
#endif
