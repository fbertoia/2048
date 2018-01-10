/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexfct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 04:06:14 by bteissei          #+#    #+#             */
/*   Updated: 2017/05/10 07:29:24 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t a;

	a = 0;
	while (a < len && src[a] != '\0')
	{
		dst[a] = src[a];
		a++;
	}
	while (a < len)
	{
		dst[a] = '\0';
		a++;
	}
	return (dst);
}

int			ft_atoi(const char *str)
{
	int i;
	int result;
	int negative;

	negative = 0;
	result = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= 48) && (str[i] <= 57))
	{
		result = result * 10;
		result = result + ((int)str[i] - 48);
		i++;
	}
	if (negative == 1)
		return (-result);
	return (result);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strcpy(char *dst, const char *src)
{
	int a;

	a = 0;
	while (src[a] != '\0')
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (dst);
}

void		ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putcount(s[i], 1);
		i++;
	}
}
