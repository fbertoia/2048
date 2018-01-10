/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexfcto.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 07:13:08 by bteissei          #+#    #+#             */
/*   Updated: 2017/05/10 07:17:27 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char	*returnlongo(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, unsigned long), 8)))
		return (NULL);
	return (str);
}

char	*returnlonglongo(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, unsigned long long), 8)))
		return (NULL);
	return (str);
}

char	*returnintmaxo(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, uintmax_t), 8)))
		return (NULL);
	return (str);
}

char	*returnsizeto(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, ssize_t), 8)))
		return (NULL);
	return (str);
}

char	*checklongueuro(t_sides *sides, va_list ap)
{
	if (sides->longueur == 11)
		return (returninto(ap));
	else if (sides->longueur == 1)
		return (returninto(ap));
	else if (sides->longueur == 22)
		return (returnlongo(ap));
	else if (sides->longueur == 2)
		return (returnlonglongo(ap));
	else if (sides->longueur == 0)
		return (returninto(ap));
	else if (sides->longueur == 5)
		return (returnintmaxo(ap));
	else if (sides->longueur == 8)
		return (returnsizeto(ap));
	return (NULL);
}
