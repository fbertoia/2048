/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktruc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 07:05:17 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 07:37:38 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int				checkmove(int **tab)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i > 0 && tab[i - 1][j] == tab[i][j])
				return (1);
			if (j > 0 && tab[i][j - 1] == tab[i][j])
				return (1);
			if (i < 3 && tab[i + 1][j] == tab[i][j])
				return (1);
			if (j < 3 && tab[i][j + 1] == tab[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
