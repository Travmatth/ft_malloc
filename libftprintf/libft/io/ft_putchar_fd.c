/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:56:19 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:28:31 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** ft_putchar_fd
** Description Outputs the char c to the file descriptor fd.
** Param. #1 The character to output.
** Param. #2 The file descriptor.
** Return value None.
** Libc functions write(2).
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
