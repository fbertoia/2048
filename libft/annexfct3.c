/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexfct3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 07:28:10 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/06 10:13:30 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if (!(ptr = malloc(size)))
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

int		setfd(int fd, int mode)
{
	static int fdp = 1;

	if (mode)
		fdp = fd;
	else
		return (fdp);
	return (1);
}

int		ft_fdprintf(int fd, const char *format, ...)
{
	va_list	ap;
	char	*str;

	setfd(fd, 1);
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
