/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 16:45:58 by tmatthew          #+#    #+#             */
/*   Updated: 2018/06/26 16:47:10 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

typedef union				u_val
{
	void					*void_ptr;
	short int				signed_short;
	unsigned short int		unsigned_short;
	short int				*short_ptr;

	int						signed_int;
	unsigned				unsigned_int;
	int						*int_ptr;

	long int				*long_ptr;
	long int				signed_long;
	unsigned long			unsigned_long;

	long double				long_double;
	double					signed_double;

	long long int			*llong_ptr;
	unsigned long long		unsigned_llong;
	long long int			signed_llong;

	char					signed_char;
	unsigned char			unsigned_char;
	char					*str;
	wchar_t					*wide_char;

	wint_t					wide_int;
	size_t					sz_t;
	uintptr_t				uintptr;
	ptrdiff_t				ptr_diff;
	ptrdiff_t				*diffptr;
	intmax_t				intmax;
	intmax_t				*intmax_ptr;
	uintmax_t				uintmax;
	size_t					sizet;
	ssize_t					ssizet;
	size_t					*sizet_ptr;
}							t_val;

#endif
