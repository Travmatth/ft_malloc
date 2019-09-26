/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:57:51 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:32 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_putendl_fd
** Description Outputs the string s to the file descriptor fd followed by a
** ’\n’.
** Param. #1 The string to output.
** Param. #2 The file descriptor.
** Return value None.
** Libc functions write(2).
*/

void	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
