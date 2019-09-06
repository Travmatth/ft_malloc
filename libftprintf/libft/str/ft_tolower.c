/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:36:45 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/19 18:29:58 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** tolower, tolower_l -- upper case to lower case letter conversion
**
** DESCRIPTION
** The tolower() function converts an upper-case letter to the corresponding
** lower-case letter.  The argument must be representable as an unsigned
** char or the value of EOF. The tolower() function uses the current locale
**
** RETURN VALUES
** If the argument is an upper-case letter, the tolower() function returns
** the corresponding lower-case letter if there is one; otherwise, the argu-
** ment is returned unchanged.
*/

int		ft_tolower(int c)
{
	return ((c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c);
}
