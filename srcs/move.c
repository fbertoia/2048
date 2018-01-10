/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 03:53:36 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 13:50:09 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	move_right2(int i, int j, int **tab)
{
	int save;

	save = tab[i][j];
	tab[i][j] = 0;
	while (tab[i][j] == 0 && j < 3)
		j++;
	if (tab[i][j] == save)
		tab[i][j] *= 2;
	else if (tab[i][j] != save && tab[i][j] != 0)
		tab[i][j - 1] = save;
	else
		tab[i][j] = save;
}

void		move_right(int **tab)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 3;
		while (j >= 0)
		{
			if (tab[i][j] != 0)
			{
				move_right2(i, j, tab);
			}
			j--;
		}
		i++;
	}
}
