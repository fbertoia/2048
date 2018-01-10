/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 05:37:37 by bteissei          #+#    #+#             */
/*   Updated: 2017/12/09 08:40:08 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char	*ft_putstrc(char *str, int mode)
{
	int i;

	i = 0;
	while (str[i] && str[i] != mode)
	{
		ft_putcount(str[i], 1);
		i++;
	}
	return (&str[i]);
}

char	*setthemode(char *str, int *mode, int i)
{
	if (i)
	{
		str[0] = i;
		*mode = 0;
	}
	else if (i != 10)
	{
		str[0] = 10;
		*mode = 10;
	}
	else
	{
		str[0] = 11;
		*mode = 11;
	}
	return (str);
}

int		printc(t_sides *sides, int i)
{
	char	*str;
	int		mode;
	char	*save;

	if (!(str = (char*)ft_memalloc(sizeof(char) * 2)))
		return (0);
	str = setthemode(str, &mode, i);
	str[1] = '\0';
	if (!(str = leftalign(sides, str)))
		return (0);
	if (!(str = rightalign(sides, str)))
		return (0);
	save = ft_putstrc(str, mode);
	if (*save)
	{
		ft_putcount('\0', 1);
		ft_putstrc(save + 1, 0);
	}
	save = NULL;
	ft_memdel((void**)&str);
	return (1);
}

int		parsec(t_sides *sides, va_list ap)
{
	int i;

	if (sides->longueur == 2)
	{
		parselc(sides, ap);
		return (1);
	}
	i = va_arg(ap, int);
	if (!(printc(sides, i)))
		return (0);
	return (1);
}
