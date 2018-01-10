/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 05:28:18 by bteissei          #+#    #+#             */
/*   Updated: 2017/05/10 07:19:13 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char	*checkdiesex(char *str, int mode)
{
	char	*test;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str);
	if (!(test = (char*)ft_memalloc(sizeof(char) * (i + 3))))
		return (NULL);
	i = 0;
	test[j++] = '0';
	test[j++] = (mode ? 'x' : 'X');
	while (str[i])
		test[j++] = str[i++];
	test[j] = '\0';
	ft_memdel((void**)&str);
	return (test);
}

char	*lowercase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'F') || str[i] == 'X')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*swapx(char *str)
{
	char *test;

	if (ft_strchr(str, 'x'))
	{
		test = ft_strchr(str, 'x');
		*test = '0';
		str[1] = 'x';
	}
	return (str);
}

char	*parsexann(char *str, int mode, int j, t_sides *sides)
{
	int		i;

	i = 0;
	if (str[0] == '0')
		i++;
	if (!(str = checkprecisionx(sides, str)))
		return (NULL);
	if ((j) && !(i) && sides->attributs->diese != 0)
		if (!(str = checkdiesex(str, mode)))
			return (NULL);
	if (!(str = leftalign(sides, str)))
		return (NULL);
	if (!(str = rightalign(sides, str)))
		return (NULL);
	if (sides->attributs->zero != 0)
	{
		while (str[i] && str[i] == ' ')
			str[i++] = '0';
		swapx(str);
	}
	return (str);
}

int		parsex(t_sides *sides, va_list ap, int mode)
{
	char	*str;
	int		j;

	j = 1;
	if (!(str = checklongueurx(sides, ap)))
		return (0);
	if (mode == 2 && str[0] == '0' && str[1] == '\0')
	{
		ft_putstr("0x0");
		ft_memdel((void**)&str);
		return (1);
	}
	if (str[0] == '0' && str[1] == '\0' && sides->precision == -1)
	{
		j = 0;
		str[0] = '\0';
	}
	str = parsexann(str, mode, j, sides);
	if (mode)
		str = lowercase(str);
	ft_putstr(str);
	ft_memdel((void**)&str);
	return (1);
}
