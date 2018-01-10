/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 03:38:05 by bteissei          #+#    #+#             */
/*   Updated: 2017/05/10 07:14:02 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char	*checkprecisiono(t_sides *sides, char *str)
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

char	*checkdiese(char *str)
{
	char	*test;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str);
	if (!(test = (char*)ft_memalloc(sizeof(char) * (i + 2))))
		return (NULL);
	i = 0;
	test[j++] = '0';
	while (str[i])
		test[j++] = str[i++];
	test[j] = '\0';
	ft_memdel((void**)&str);
	return (test);
}

int		parseo(t_sides *sides, va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = checklongueuro(sides, ap)))
		return (0);
	if (str[0] == '0' && str[1] == '\0' && sides->precision == -1)
		str[0] = '\0';
	if (str[0] != '0' && sides->attributs->diese != 0)
		if (!(str = checkdiese(str)))
			return (0);
	if (!(str = checkprecisiono(sides, str)))
		return (0);
	if (!(str = leftalign(sides, str)))
		return (0);
	if (!(str = rightalign(sides, str)))
		return (0);
	if (sides->attributs->zero != 0)
		while (str[i] && str[i] == ' ')
			str[i++] = '0';
	ft_putstr(str);
	ft_memdel((void**)&str);
	return (1);
}
