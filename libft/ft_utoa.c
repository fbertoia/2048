/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:53:07 by bteissei          #+#    #+#             */
/*   Updated: 2017/12/09 08:39:52 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tf_printf.h"

static char			*copy(char *str, unsigned long long n, unsigned int base)
{
	unsigned long long	temp;
	unsigned long long	j;
	int					i;

	i = 0;
	j = 0;
	while (n >= base)
	{
		temp = n;
		while (j >= base)
		{
			j = temp % base;
			temp = temp / base;
		}
		j = temp % base;
		str[i++] = (char)j + (j < 10 ? 48 : 55);
		temp = temp / base;
		n = temp;
	}
	str[i] = (char)n + (n < 10 ? 48 : 55);
	i++;
	str[i] = '\0';
	return (str);
}

static char			*strrev(char *str)
{
	char	a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	i--;
	while (j < i)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
		j++;
		i--;
	}
	return (str);
}

char				*ft_utoa(unsigned long long n, unsigned int base)
{
	unsigned long long		i;
	unsigned long long		j;
	char					*str;

	i = 0;
	j = n;
	while (j >= base)
	{
		i++;
		j = j / base;
	}
	if (!(str = (char*)ft_memalloc(i + 2)))
		return (NULL);
	str = (copy(str, n, base));
	str = strrev(str);
	return (str);
}
