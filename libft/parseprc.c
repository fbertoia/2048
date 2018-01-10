/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseprc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 07:20:32 by bteissei          #+#    #+#             */
/*   Updated: 2017/05/10 04:20:52 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

void	okattributs(char *str, t_sides *sides)
{
	int i;

	i = 1;
	while (str[i] != '%')
	{
		if (str[i] == '-' && str[i - 1] != '.')
			sides->attributs->minus = 1;
		i++;
	}
}

void	oklargeur(char *str, t_sides *sides)
{
	int i;

	i = 1;
	sides->largeur = 0;
	while (str[i] != '%')
	{
		if (str[i] == '.')
		{
			i++;
			if (str[i] == '-')
				i++;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		if (str[i] >= '1' && str[i] <= '9')
		{
			sides->largeur = ft_atoi(&str[i]);
			break ;
		}
		if (str[i] == '%')
			break ;
		i++;
	}
}

int		parseprc(t_sides *sides)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * 2)))
		return (0);
	str[0] = '%';
	str[1] = '\0';
	if (!(str = leftalign(sides, str)))
		return (0);
	if (!(str = rightalign(sides, str)))
		return (0);
	ft_putstr(str);
	ft_memdel((void**)&str);
	return (1);
}
