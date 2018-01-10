/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 02:04:21 by bteissei          #+#    #+#             */
/*   Updated: 2017/12/09 08:40:00 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

int		getattributs(char *str, char *end, t_sides *sides)
{
	int i;
	int point;

	if (!(sides->attributs = (t_attribut*)ft_memalloc(sizeof(t_attribut))))
		return (0);
	sides->attributs->diese = 0;
	sides->attributs->minus = 0;
	sides->attributs->plus = 0;
	sides->attributs->space = 0;
	sides->attributs->zero = 0;
	point = 0;
	i = 0;
	getattrann(sides, str, end, &point);
	while (str[i] != *end)
	{
		if (str[i] == '0' && sides->attributs->minus != 1 && point == 0
				&& !(str[i - 1] >= '0' && str[i - 1] <= '9'))
			sides->attributs->zero = 1;
		else if (str[i] == ' ' && sides->attributs->plus == 0)
			sides->attributs->space = 1;
		i++;
	}
	return (1);
}

void	getlargeur(char *str, char *end, t_sides *sides)
{
	int i;

	i = 0;
	sides->largeur = 0;
	while (str[i] != *end)
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
		if (str[i] == *end)
			break ;
		i++;
	}
}

void	getprecision(char *str, char *end, t_sides *sides)
{
	int i;

	i = 0;
	sides->precision = 0;
	while (str[i] != *end)
	{
		if (str[i] == '.')
		{
			i++;
			if (!(str[i] >= '0' && str[i] <= '9'))
			{
				if (sides->precision == 0)
					sides->precision = -1;
				break ;
			}
			sides->precision = ft_atoi(&str[i]);
			if (sides->precision == 0)
				sides->precision = -1;
			break ;
		}
		i++;
	}
}

void	getlongueur2(char *str, t_sides *sides)
{
	if (str[0] == 'h')
	{
		if (str[1] == 'h')
			sides->longueur = 11;
		else
			sides->longueur = 1;
	}
	if (str[0] == 'l')
	{
		if (str[1] == 'l')
			sides->longueur = 22;
		else
			sides->longueur = 2;
	}
	if (str[0] == 'j')
		sides->longueur = 5;
	if (str[0] == 'z')
		sides->longueur = 8;
}

void	getlongueur(char *str, char *end, t_sides *sides)
{
	int i;

	sides->longueur = 0;
	i = 0;
	while (str[i] != *end)
	{
		if (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z')
		{
			getlongueur2(&str[i], sides);
			break ;
		}
		i++;
	}
}
