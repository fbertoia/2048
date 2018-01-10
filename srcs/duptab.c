/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duptab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 07:05:50 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 07:10:16 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		**duptab(int **oldtab)
{
	int i;
	int **tab;
	int j;

	i = 0;
	if (!(tab = ft_memalloc(sizeof(int*) * 4)))
		return (NULL);
	while (i < 4)
	{
		j = 0;
		if (!(tab[i] = ft_memalloc(sizeof(int) * 4)))
			return (NULL);
		while (j < 4)
		{
			tab[i][j] = oldtab[i][j];
			j++;
		}
		i++;
	}
	return (tab);
}
