/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:17:45 by tmatthew          #+#    #+#             */
/*   Updated: 2019/09/30 17:20:19 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/internal.h"

void	fmt_pointer(int fd, char buf[19], va_list ap)
{
	size_t	len;
	int		i;

	len = ft_intmaxtoa_base(buf, (intmax_t)va_arg(ap, ULL), 16, HEX);
	i = len - 1;
	while (i >= 0)
	{
		buf[18 - len + i] = buf[i];
		i -= 1;
	}
	i = 2;
	buf[0] = '0';
	buf[1] = 'x';
	len = 16 - len + 1;
	while (--len)
		buf[i++] = '0';
	buf[18] = '\0';
	write(fd, buf, 18);
}

void	fmt_print(int fd, const char *fmt, int *idx, va_list ap)
{
	char	buf[19];
	size_t	len;

	*idx += 1;
	if (!fmt[*idx])
		return ;
	if (fmt[*idx] == 'd')
	{
		len = ft_intmaxtoa_base(buf, (intmax_t)va_arg(ap, int), 10, DEC);
		write(fd, buf, len);
	}
	else if (fmt[*idx] == 'z' && fmt[*idx + 1] == 'u')
	{
		len = ft_intmaxtoa_base(buf, (intmax_t)va_arg(ap, size_t), 10, DEC);
		write(fd, buf, len);
		*idx += 1;
	}
	else if (fmt[*idx] == 'p')
		fmt_pointer(fd, buf, ap);
	*idx += 1;
}

void	nomalloc_log(int fd, const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		start;
	char	*spec;

	i = 0;
	va_start(ap, fmt);
	while (1)
	{
		if (!fmt[i])
			break ;
		else if (fmt[i] == '%')
			fmt_print(fd, fmt, &i, ap);
		start = i;
		spec = (char*)&fmt[start];
		while (fmt[i] && fmt[i] != '%')
			i += 1;
		write(fd, spec, i - start);
	}
	va_end(ap);
}
