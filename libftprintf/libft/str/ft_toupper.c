/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:35:38 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:57 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** toupper, toupper_l -- lower case to upper case letter conversion
**
** DESCRIPTION
** The toupper() function converts a lower-case letter to the corresponding
** upper-case letter.  The argument must be representable as an unsigned
** char or the value of EOF. The toupper() function uses the current locale.
**
** RETURN VALUES
** If the argument is a lower-case letter, the toupper() function returns
** the corresponding upper-case letter if there is one; otherwise, the argu-
** ment is returned unchanged.
*/

int		ft_toupper(int c)
{
	return ((c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c);
}
