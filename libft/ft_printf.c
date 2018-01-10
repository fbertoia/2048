/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 02:41:28 by bteissei          #+#    #+#             */
/*   Updated: 2017/12/09 08:39:11 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "tf_printf.h"

int		parseconvann(char *end, t_sides *sides, va_list ap)
{
	if (*end == 'u')
		if (!(parseu(sides, ap)))
			return (0);
	if (*end == 'U')
	{
		sides->longueur = 2;
		if (!(parseu(sides, ap)))
			return (0);
	}
	if (*end == 'x')
		if (!(parsex(sides, ap, 1)))
			return (0);
	if (*end == 'X')
		if (!(parsex(sides, ap, 0)))
			return (0);
	if (*end == 'c')
		if (!(parsec(sides, ap)))
			return (0);
	if (*end == 'C')
		if (!(parselc(sides, ap)))
			return (0);
	if (*end == '%')
		if (!(parseprc(sides)))
			return (0);
	return (parseconvann2(end, sides, ap));
}

int		parseconv(char *end, t_sides *sides, va_list ap)
{
	if (*end == 's')
		if (!(parses(sides, ap)))
			return (0);
	if (*end == 'S')
		if (!(parsels(sides, ap)))
			return (0);
	if (*end == 'p')
		if (!(parsep(sides, ap)))
			return (0);
	if (*end == 'd' || *end == 'i')
		if (!(parsed(sides, ap)))
			return (0);
	return (parseconvann(end, sides, ap));
}

int		parseall(char *str, char *end, va_list ap)
{
	t_sides		*sides;

	if (!(sides = (t_sides*)ft_memalloc(sizeof(t_sides))))
		return (0);
	if (!(getattributs(str, end, sides)))
		return (0);
	getlargeur(str, end, sides);
	getlongueur(str, end, sides);
	getprecision(str, end, sides);
	if (*end == '%')
	{
		oklargeur(str, sides);
		okattributs(str, sides);
	}
	if (!(parseconv(end, sides, ap)))
		return (0);
	ft_memdel((void**)(&(sides->attributs)));
	ft_memdel((void**)&sides);
	return (1);
}

char	*checkarg(char *str, va_list ap)
{
	int i;

	i = 1;
	while (str[i] && str[i] != 's' && str[i] != 'S' && str[i] != 'p'
			&& str[i] != 'd' && str[i] != 'D' && str[i] != 'i' && str[i] != 'o'
			&& str[i] != 'O' && str[i] != 'u' && str[i] != 'U' && str[i] != 'x'
			&& str[i] != 'X' && str[i] != 'c' && str[i] != 'C' && str[i] != '%')
		i++;
	if (!(parseall(str, &str[i], ap)))
		return (NULL);
	if (!(str[i]))
		return (&str[i]);
	return (&str[i + 1]);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;

	setfd(1, 1);
	str = (char*)format;
	va_start(ap, format);
	while (*str)
	{
		str = (printuntil(str));
		if (*str == '%')
			if (!(str = checkarg(str, ap)))
				return (-1);
	}
	va_end(ap);
	return (ft_putcount('c', 0));
}
