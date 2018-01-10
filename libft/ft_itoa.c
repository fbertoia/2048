/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:53:07 by bteissei          #+#    #+#             */
/*   Updated: 2017/12/09 08:41:46 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tf_printf.h"

static char			*copy(char *str, long long n, int neg, int base)
{
	long long	temp;
	long long	j;
	int			i;

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
	if (neg == 1)
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

static void			checkneg(long long *n, int *neg)
{
	if (*n < 0)
	{
		*n = -(*n);
		*neg = 1;
	}
	else
		*neg = 0;
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

char				*longmin(void)
{
	char *str;

	if (!(str = (char*)ft_memalloc(sizeof(char) * 21)))
		return (NULL);
	str[0] = '-';
	str[1] = '9';
	str[2] = '2';
	str[3] = '2';
	str[4] = '3';
	str[5] = '3';
	str[6] = '7';
	str[7] = '2';
	str[8] = '0';
	str[9] = '3';
	str[10] = '6';
	str[11] = '8';
	str[12] = '5';
	str[13] = '4';
	str[14] = '7';
	str[15] = '7';
	str[16] = '5';
	str[17] = '8';
	str[18] = '0';
	str[20] = '\0';
	return (str);
}

char				*ft_itoa(long long n, int base)
{
	long long		i;
	long long		j;
	char			*str;
	int				neg;

	i = 0;
	if (n == -9223372036854775807 - 1)
	{
		if (!(str = longmin()))
			return (NULL);
		str[19] = '8';
		return (str);
	}
	checkneg(&n, &neg);
	j = n;
	while (j >= base)
	{
		i++;
		j = j / base;
	}
	if (!(str = (char*)ft_memalloc(i + neg + 2)))
		return (NULL);
	str = (copy(str, n, neg, base));
	str = strrev(str);
	return (str);
}
