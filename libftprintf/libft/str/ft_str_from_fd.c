/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_from_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:15:17 by tmatthew          #+#    #+#             */
/*   Updated: 2018/10/16 17:39:38 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** reads a given fd and returns a string with its contents
*/

int		append_buf(char **str, char *buf, size_t bytes, size_t *total)
{
	char	*next;

	if (!(next = (char*)ft_strnew(*total + bytes)))
		return (-1);
	ft_memcpy((void*)(next), (void*)*str, *total);
	ft_memcpy((void*)(next + *total), (void*)buf, bytes);
	*total += bytes;
	free(*str);
	*str = next;
	return (bytes < BUFF_SIZE ? 1 : 0);
}

size_t	ft_str_from_fd(int fd, char **str)
{
	size_t	bytes;
	size_t	total;
	char	buf[BUFF_SIZE];
	int		ret;

	total = 0;
	while ((bytes = read(fd, buf, BUFF_SIZE)))
	{
		ret = append_buf(str, buf, bytes, &total);
		if (ERR(ret))
			return (0);
		else if (ret)
			break ;
	}
	return (total);
}
