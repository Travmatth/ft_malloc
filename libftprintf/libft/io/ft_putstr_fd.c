/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:00:37 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:38 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_putstr_fd
** Description Outputs the string s to the file descriptor fd.
** Param. #1 The string to output.
** Param. #2 The file descriptor.
** Return value None.
** Libc functions write(2).
*/

void	ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
