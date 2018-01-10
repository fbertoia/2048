/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 02:31:44 by bteissei          #+#    #+#             */
/*   Updated: 2017/05/10 07:12:41 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char	*checkprecisionu(t_sides *sides, char *str)
{
	int		i;
	char	*res;
	int		tmp;
	int		j;

	j = 0;
	tmp = 0;
	i = ft_strlen(str);
	if (sides->precision > i - 1)
	{
		if (!(res = (char*)ft_memalloc(sizeof(char) * (sides->precision + 1))))
			return (NULL);
		while (tmp < sides->precision - i)
			res[tmp++] = '0';
		while (str[j])
			res[tmp++] = str[j++];
		ft_memdel((void**)&str);
		return (res);
	}
	return (str);
}

int		parseu(t_sides *sides, va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = checklongueuru(sides, ap)))
		return (0);
	if (str[0] == '0' && str[1] == '\0' && sides->precision == -1)
		str[0] = '\0';
	if (!(str = checkprecisionu(sides, str)))
		return (0);
	if (!(str = leftalign(sides, str)))
		return (0);
	if (!(str = rightalign(sides, str)))
		return (0);
	if (sides->attributs->zero != 0)
		while (str[i] && str[i] == ' ')
			str[i++] = '0';
	ft_putstr(str);
	ft_memdel((void**)&str);
	return (1);
}
