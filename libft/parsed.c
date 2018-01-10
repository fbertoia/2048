/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 01:54:51 by bteissei          #+#    #+#             */
/*   Updated: 2017/05/10 07:22:30 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char	*checkprecisiond(t_sides *sides, char *str, int j, int tmp)
{
	int		i;
	char	*res;
	int		n;

	i = ft_strlen(str);
	n = (ft_strchr(str, '-')) ? 1 : 0;
	if (sides->precision > i - 1)
	{
		if (!(res = (char*)ft_memalloc(sides->precision + 1 + n)))
			return (NULL);
		while (tmp < sides->precision - i + n)
			res[tmp++] = '0';
		while (str[j])
			res[tmp++] = str[j++];
		ft_memdel((void**)&str);
		if (n)
		{
			str = ft_strchr(res, '-');
			*str = '0';
			res[0] = '-';
		}
		res[tmp] = '\0';
		return (res);
	}
	return (str);
}

char	*checkflags(t_sides *sides, char *str)
{
	int		i;
	char	*res;
	int		j;
	int		n;

	i = 0;
	j = 0;
	n = (ft_strchr(str, '-')) ? 1 : 0;
	if ((sides->attributs->space != 0 || sides->attributs->plus != 0) && !(n))
	{
		if (!(res = (char*)ft_memalloc(sizeof(char) * (ft_strlen(str)) + 2)))
			return (NULL);
		res[j++] = (sides->attributs->plus != 0) ? '+' : ' ';
		while (str[i])
			res[j++] = str[i++];
		ft_memdel((void**)&str);
		return (res);
	}
	return (str);
}

char	*checklongueurd(t_sides *sides, va_list ap)
{
	if (sides->longueur == 11)
		return (returnint(ap));
	else if (sides->longueur == 1)
		return (returnint(ap));
	else if (sides->longueur == 22)
		return (returnlong(ap));
	else if (sides->longueur == 2)
		return (returnlonglong(ap));
	else if (sides->longueur == 0)
		return (returnint(ap));
	else if (sides->longueur == 5)
		return (returnintmax(ap));
	else if (sides->longueur == 8)
		return (returnsizet(ap));
	return (NULL);
}

char	*parsedann(t_sides *sides, char *str)
{
	int		i;
	char	*test;

	i = 0;
	if (sides->attributs->space != 0)
		i++;
	while (str[i] && str[i] == ' ')
		str[i++] = '0';
	if (ft_strchr(str, '-'))
	{
		test = ft_strchr(str, '-');
		*test = '0';
		str[0] = '-';
	}
	else if (sides->attributs->plus != 0)
	{
		test = ft_strchr(str, '+');
		*test = '0';
		str[0] = '+';
	}
	return (str);
}

int		parsed(t_sides *sides, va_list ap)
{
	char	*str;
	int		j;
	int		tmp;

	j = 0;
	tmp = 0;
	if (!(str = checklongueurd(sides, ap)))
		return (0);
	if (str[0] == '0' && str[1] == '\0' && sides->precision == -1)
		str[0] = '\0';
	if (!(str = checkprecisiond(sides, str, j, tmp)))
		return (0);
	if (!(str = checkflags(sides, str)))
		return (0);
	if (!(str = leftalign(sides, str)))
		return (0);
	if (!(str = rightalign(sides, str)))
		return (0);
	if (sides->attributs->zero != 0)
		str = parsedann(sides, str);
	ft_putstr(str);
	ft_memdel((void**)&str);
	return (1);
}
