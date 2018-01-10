/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsels.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 05:59:09 by bteissei          #+#    #+#             */
/*   Updated: 2017/12/09 08:40:57 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char	*printls(wchar_t wchar)
{
	unsigned int	i;
	int				size;
	char			*str;

	str = NULL;
	i = (int)wchar;
	size = checkbitsign(i);
	if (size <= 8)
		str = prints(i);
	else if (size <= 11)
		str = givemetwo(i);
	else if (size <= 16)
		str = givemethree(i);
	else
		str = givemefour(i, str);
	return (str);
}

char	*joinnoleaks(char *str, char *copy)
{
	char *test;

	if (!(test = ft_strjoin(str, copy)))
		return (0);
	ft_memdel((void **)&str);
	ft_memdel((void **)&copy);
	return (test);
}

char	*parselsann5(t_sides *sides, wchar_t *tmp, int y, int i)
{
	int		x;
	char	*str;
	char	*copy;

	x = sides->precision;
	if (!(str = (char*)ft_memalloc(sizeof(char) * 1)))
		return (0);
	while (tmp[i])
	{
		copy = printls(tmp[i]);
		if (x)
		{
			y += ft_strlen(copy);
			if (y > x)
			{
				ft_memdel((void **)&copy);
				break ;
			}
		}
		str = joinnoleaks(str, copy);
		i++;
	}
	return (str);
}

char	*getnull(char *str)
{
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}

int		parsels(t_sides *sides, va_list ap)
{
	char	*str;
	int		i;
	wchar_t	*tmp;
	int		y;

	i = 0;
	y = 0;
	tmp = va_arg(ap, wchar_t*);
	if (!(tmp))
	{
		if (!(str = (char*)ft_memalloc(sizeof(char) * 7)))
			return (0);
		str = getnull(str);
		str = dosprecision(sides, str);
	}
	else if (!(str = parselsann5(sides, tmp, y, i)))
		return (0);
	if (!(str = leftalign(sides, str)))
		return (0);
	if (!(str = rightalign(sides, str)))
		return (0);
	ft_putstr(str);
	ft_memdel((void**)&str);
	return (1);
}
