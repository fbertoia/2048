/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexfctuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 07:04:13 by bteissei          #+#    #+#             */
/*   Updated: 2017/05/10 07:18:03 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char	*returnlongu(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, unsigned long), 10)))
		return (NULL);
	return (str);
}

char	*returnlonglongu(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, unsigned long long), 10)))
		return (NULL);
	return (str);
}

char	*returnintmaxu(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, uintmax_t), 10)))
		return (NULL);
	return (str);
}

char	*returnsizetu(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, ssize_t), 10)))
		return (NULL);
	return (str);
}

char	*checklongueuru(t_sides *sides, va_list ap)
{
	if (sides->longueur == 11)
		return (returnintu(ap));
	else if (sides->longueur == 1)
		return (returnintu(ap));
	else if (sides->longueur == 22)
		return (returnlongu(ap));
	else if (sides->longueur == 2)
		return (returnlonglongu(ap));
	else if (sides->longueur == 0)
		return (returnintu(ap));
	else if (sides->longueur == 5)
		return (returnintmaxu(ap));
	else if (sides->longueur == 8)
		return (returnsizetu(ap));
	return (NULL);
}
