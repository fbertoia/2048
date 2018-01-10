/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexfctx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 07:13:13 by bteissei          #+#    #+#             */
/*   Updated: 2017/05/10 07:17:34 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char	*returnlongx(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, unsigned long), 16)))
		return (NULL);
	return (str);
}

char	*returnlonglongx(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, unsigned long long), 16)))
		return (NULL);
	return (str);
}

char	*returnintmaxx(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, uintmax_t), 16)))
		return (NULL);
	return (str);
}

char	*returnsizetx(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, ssize_t), 16)))
		return (NULL);
	return (str);
}

char	*checklongueurx(t_sides *sides, va_list ap)
{
	if (sides->longueur == 11)
		return (returnintx(ap));
	else if (sides->longueur == 1)
		return (returnintx(ap));
	else if (sides->longueur == 22)
		return (returnlongx(ap));
	else if (sides->longueur == 2)
		return (returnlonglongx(ap));
	else if (sides->longueur == 0)
		return (returnintx(ap));
	else if (sides->longueur == 5)
		return (returnintmaxx(ap));
	else if (sides->longueur == 8)
		return (returnsizetx(ap));
	return (NULL);
}
