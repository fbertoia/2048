/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexfct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 07:28:06 by bteissei          #+#    #+#             */
/*   Updated: 2017/12/09 08:42:32 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	k = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(str = (char*)(ft_memalloc(sizeof(char) * (i + j + 1)))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	while (s2[j])
		str[k++] = s2[j++];
	str[k] = '\0';
	return (str);
}

void		ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

char		*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (s[i] == c)
		return ((char*)&s[i]);
	while (s[i])
	{
		i++;
		if (s[i] == c)
			return ((char*)&s[i]);
	}
	return (NULL);
}

void		ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}

char		*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	ptr = (char*)ft_memalloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
		return (NULL);
	while (j < i)
	{
		ptr[j] = s1[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
