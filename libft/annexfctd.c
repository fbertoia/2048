/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexfctd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 07:20:34 by bteissei          #+#    #+#             */
/*   Updated: 2017/05/10 07:22:46 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char	*returnint(va_list ap)
{
	char *str;

	if (!(str = ft_itoa(va_arg(ap, int), 10)))
		return (NULL);
	return (str);
}

char	*returnlong(va_list ap)
{
	char *str;

	if (!(str = ft_itoa(va_arg(ap, long), 10)))
		return (NULL);
	return (str);
}

char	*returnlonglong(va_list ap)
{
	char *str;

	if (!(str = ft_itoa(va_arg(ap, long long), 10)))
		return (NULL);
	return (str);
}

char	*returnintmax(va_list ap)
{
	char *str;

	if (!(str = ft_itoa(va_arg(ap, intmax_t), 10)))
		return (NULL);
	return (str);
}

char	*returnsizet(va_list ap)
{
	char *str;

	if (!(str = ft_itoa(va_arg(ap, size_t), 10)))
		return (NULL);
	return (str);
}
