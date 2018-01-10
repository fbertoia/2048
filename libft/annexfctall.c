/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexfctall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 07:15:27 by bteissei          #+#    #+#             */
/*   Updated: 2017/12/09 08:38:38 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char	*returnintx(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, unsigned int), 16)))
		return (NULL);
	return (str);
}

char	*returnintu(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, unsigned int), 10)))
		return (NULL);
	return (str);
}

char	*returninto(va_list ap)
{
	char *str;

	if (!(str = ft_utoa(va_arg(ap, unsigned int), 8)))
		return (NULL);
	return (str);
}

char	*prints(int i)
{
	char *str;

	if (!(str = (char*)ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	if (i)
	{
		str[0] = i;
		str[1] = '\0';
	}
	return (str);
}

char	*checkprecisionx(t_sides *sides, char *str)
{
	int		i;
	char	*res;
	int		tmp;
	int		j;

	j = 0;
	tmp = 0;
	i = ft_strlen(str);
	if (sides->precision > i - 1)
	{
		if (!(res = (char*)ft_memalloc(sizeof(char) * (sides->precision + 1))))
			return (NULL);
		while (tmp < sides->precision - i)
			res[tmp++] = '0';
		while (str[j])
			res[tmp++] = str[j++];
		res[tmp] = '\0';
		ft_memdel((void**)&str);
		return (res);
	}
	return (str);
}
