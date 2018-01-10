/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexfctall2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 07:23:15 by bteissei          #+#    #+#             */
/*   Updated: 2017/11/27 07:13:38 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

int		ft_putcount(char c, int mode)
{
	static char	buff[4096];
	static int	i = 0;
	static int	i2;
	int			j;

	if (i2 == 4096)
	{
		write(setfd(1, 0), buff, i2);
		i2 = 0;
		ft_bzero(buff, i2);
	}
	if (mode)
	{
		buff[i2] = c;
		i++;
		i2++;
		return (1);
	}
	write(setfd(1, 0), buff, i2);
	i2 = 0;
	j = i;
	i = 0;
	return (j);
}

char	*printuntil(char *str)
{
	while (*str && *str != '%')
	{
		ft_putcount(*str, 1);
		str++;
	}
	return (str);
}

int		parseconvann2(char *end, t_sides *sides, va_list ap)
{
	if (*end == 'D')
	{
		sides->longueur = 2;
		if (!(parsed(sides, ap)))
			return (0);
	}
	if (*end == 'o')
		if (!(parseo(sides, ap)))
			return (0);
	if (*end == 'O')
	{
		sides->longueur = 2;
		if (!(parseo(sides, ap)))
			return (0);
	}
	return (1);
}

int		checkbitsign(int i)
{
	int res;
	int vraires;

	vraires = 0;
	res = 1;
	while (res <= i)
	{
		res *= 2;
		vraires++;
	}
	return (vraires);
}

void	getattrann(t_sides *sides, char *str, char *end, int *point)
{
	int i;

	i = 0;
	while (str[i] != *end)
	{
		if (str[i] == '#')
			sides->attributs->diese = 1;
		else if (str[i] == '-' && str[i - 1] != '.')
			sides->attributs->minus = 1;
		else if (str[i] == '+')
			sides->attributs->plus = 1;
		else if (str[i] == '.')
			*point = 1;
		i++;
	}
}
