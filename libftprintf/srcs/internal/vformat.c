/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vformat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 18:51:45 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/30 16:11:07 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/internal.h"

/*
** make_spec
** each struct holds all the info necessary to convert one specifier
*/

t_fmt	*make_spec(t_state *state)
{
	t_fmt	next;
	size_t	offset;

	ft_bzero((void*)&next, sizeof(t_fmt));
	if ((state->in->current + sizeof(t_fmt) >= state->in->total)
		&& !(ft_bufresize(state->in)->buf))
		return (NULL);
	next.width = I_MIN;
	next.precision = I_MIN;
	offset = state->in->current - sizeof(t_fmt);
	ft_memcpy((char*)state->in->buf + offset, (void*)&next, sizeof(t_fmt));
	state->in->current += sizeof(t_fmt);
	return ((t_fmt*)((char*)state->in->buf + offset));
}

/*
** string_join
** helper function -> used by reduce to create single string
*/

void	*string_join(void *final, void *elem, size_t i, int *stop)
{
	t_fmt	*spec;
	size_t	len;
	t_cnv	*specifier_table;
	t_buf	*buf;

	(void)stop;
	spec = (t_fmt*)elem;
	specifier_table = get_cnv_table();
	if (specifier_table[(unsigned)spec->cnv])
		specifier_table[(unsigned)spec->cnv](spec);
	add_color_codes(spec);
	len = ((t_fmt*)elem)->len.out;
	if (!i)
	{
		if (!(buf = ft_bufnew(ft_memdup(spec->out, !len ? 1 : len)
							, len, !len ? 1 : len)))
			return (NULL);
		return ((void*)buf);
	}
	ft_bufappend((t_buf*)final, spec->out, spec->len.out);
	return (final);
}

/*
** init_state
** alloc memory used to hold state struct
*/

t_state	*init_state(void)
{
	size_t	size;
	t_state	*state;

	size = sizeof(t_fmt);
	if (!(state = ft_memalloc(sizeof(t_state))))
		return (NULL);
	else if (!(state->in = ft_bufnew(ft_memalloc(size), size, size)))
	{
		free(state);
		return (NULL);
	}
	return (state);
}

/*
** kill_state
** free memory used to hold formatting strings, state struct
*/

void	kill_state(t_state **state)
{
	size_t	i;
	size_t	total_len;
	t_fmt	*spec;

	i = 0;
	total_len = (*state)->in->current;
	while (i < total_len)
	{
		spec = (t_fmt*)&(((char*)(*state)->in->buf)[i]);
		ft_strdel(&spec->out);
		i += sizeof(t_fmt);
	}
	free((*state)->in->buf);
	free((*state)->in);
	if ((*state)->out)
	{
		free((*state)->out->buf);
		free((*state)->out);
	}
	free(*state);
}

/*
** vfmt_buffer
** the engine of ft_printf, all exported functions call this to
** perform formatting. Reads the format string, consumes the
** flags, field width, precision, while also handling unknown conversion
** specifiers.
*/

int		vfmt_buffer(int yield(t_buf *b, void *)
					, void *p
					, char *fmt
					, va_list ap)
{
	int		status;
	int		result;
	t_state	*state;

	if (!fmt || !(state = init_state()))
		return (-1);
	status = parse(state, fmt, ap, 0);
	state->out = (t_buf*)ft_arrfoldl(string_join
						, state->in->current / sizeof(t_fmt)
						, sizeof(t_fmt)
						, state->in->buf);
	result = yield(state->out, p);
	kill_state(&state);
	return (result);
}
