/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parselc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 01:15:21 by bteissei          #+#    #+#             */
/*   Updated: 2017/12/09 08:40:38 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char	*givemetwo(int i)
{
	unsigned char	first;
	unsigned char	second;
	unsigned int	mask;
	char			*str;

	if (!(str = (char*)ft_memalloc(sizeof(char) * 3)))
		return (NULL);
	mask = 49280;
	second = i & 0x3f;
	first = (i >> 6) & 0x1f;
	str[0] = (mask >> 8) | first;
	str[1] = (mask) | second;
	str[2] = '\0';
	return (str);
}

char	*givemethree(int i)
{
	unsigned char	first;
	unsigned char	second;
	unsigned char	third;
	unsigned int	mask;
	char			*str;

	if (!(str = (char*)ft_memalloc(sizeof(char) * 5)))
		return (NULL);
	mask = 14712960;
	third = i & 0x3f;
	second = (i >> 6) & 0x3f;
	first = (i >> 12) & 0xf;
	str[0] = (mask >> 16) | first;
	str[1] = (mask >> 8) | second;
	str[2] = (mask) | third;
	str[3] = '\0';
	return (str);
}

char	*givemefour(int i, char *str)
{
	unsigned char	first;
	unsigned char	second;
	unsigned char	third;
	unsigned char	four;
	unsigned int	mask;

	if (!(str = (char*)ft_memalloc(sizeof(char) * 5)))
		return (NULL);
	mask = 4034953344;
	four = i & 0x3f;
	third = (i >> 6) & 0x3f;
	second = (i >> 12) & 0x3f;
	first = (i >> 18) & 0x7;
	str[0] = (mask >> 24) | first;
	str[1] = (mask >> 16) | second;
	str[2] = (mask >> 8) | third;
	str[3] = (mask) | four;
	str[4] = '\0';
	return (str);
}

int		parselsann(char *str, t_sides *sides, int size, int i)
{
	if (size <= 7 || (MB_CUR_MAX == 1 && size == 8))
	{
		printc(sides, i);
		return (1);
	}
	if (MB_CUR_MAX == 1)
		return (0);
	if (size > 7 && size <= 11)
		if (!(str = givemetwo(i)))
			return (0);
	if (size > 11 && size <= 16)
		if (!(str = givemethree(i)))
			return (0);
	if (size > 16)
	{
		if (!(str = givemefour(i, str)))
			return (0);
	}
	if (!(str = leftalign(sides, str)))
		return (0);
	if (!(str = rightalign(sides, str)))
		return (0);
	ft_putstr(str);
	ft_memdel((void**)&str);
	return (1);
}

int		parselc(t_sides *sides, va_list ap)
{
	unsigned int	i;
	wchar_t			wchar;
	int				size;
	char			*str;

	str = NULL;
	wchar = va_arg(ap, wchar_t);
	if ((int)wchar < 0)
		return (0);
	i = (int)wchar;
	size = checkbitsign(i);
	if (!(parselsann(str, sides, size, i)))
		return (0);
	return (1);
}
