/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:11:39 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 13:49:59 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	move_left2(int i, int j, int **tab)
{
	int save;

	save = tab[i][j];
	tab[i][j] = 0;
	while (tab[i][j] == 0 && j > 0)
		j--;
	if (tab[i][j] == save)
		tab[i][j] *= 2;
	else if (tab[i][j] != save && tab[i][j] != 0)
		tab[i][j + 1] = save;
	else
		tab[i][j] = save;
}

void		move_left(int **tab)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] != 0)
			{
				move_left2(i, j, tab);
			}
			j++;
		}
		i++;
	}
}
