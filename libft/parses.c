/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parses.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 05:59:01 by bteissei          #+#    #+#             */
/*   Updated: 2017/12/09 08:41:17 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char	*leftalign(t_sides *sides, char *str)
{
	char	*result;
	int		i;

	i = ft_strlen(str);
	if (i < sides->largeur && sides->attributs->minus == 1)
	{
		if (!(result = (char*)ft_memalloc(sizeof(char) * (sides->largeur + 1))))
			return (NULL);
		ft_strcpy(result, str);
		while (i < sides->largeur)
			result[i++] = ' ';
		result[i] = '\0';
		ft_memdel((void**)&str);
		return (result);
	}
	return (str);
}

char	*rightalign(t_sides *sides, char *str)
{
	char	*result;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str);
	if (i < sides->largeur && sides->attributs->minus == 0)
	{
		if (!(result = (char*)ft_memalloc(sizeof(char) * (sides->largeur + 1))))
			return (NULL);
		while (j < (sides->largeur - i))
			result[j++] = ' ';
		ft_strcpy(&result[j], str);
		ft_memdel((void**)&str);
		return (result);
	}
	return (str);
}

char	*dosprecision(t_sides *sides, char *str)
{
	int i;

	i = ft_strlen(str);
	if (sides->precision != 0 && sides->precision < i)
	{
		if (sides->precision == -1)
			sides->precision = 0;
		i = sides->precision;
		while (str[i])
			str[i++] = '\0';
	}
	return (str);
}

char	*parsesann(t_sides *sides, char *str, char *tmp)
{
	if (!(tmp))
	{
		if (!(str = (char*)ft_memalloc(sizeof(char) * 7)))
			return (NULL);
		str[0] = '(';
		str[1] = 'n';
		str[2] = 'u';
		str[3] = 'l';
		str[4] = 'l';
		str[5] = ')';
		str[6] = '\0';
	}
	else
	{
		if (sides->precision == -1)
		{
			if (!(str = (char*)ft_memalloc(sizeof(char) * 1)))
				return (NULL);
			str[0] = '\0';
		}
		else if (!(str = ft_strdup(tmp)))
			return (NULL);
	}
	return (str);
}

int		parses(t_sides *sides, va_list ap)
{
	char	*str;
	char	*tmp;

	str = NULL;
	if (sides->longueur == 2)
	{
		if (!(parsels(sides, ap)))
			return (0);
		return (1);
	}
	tmp = va_arg(ap, char*);
	str = parsesann(sides, str, tmp);
	str = dosprecision(sides, str);
	if (!(str = leftalign(sides, str)))
		return (0);
	if (!(str = rightalign(sides, str)))
		return (0);
	ft_putstr(str);
	ft_memdel((void**)&str);
	return (1);
}
