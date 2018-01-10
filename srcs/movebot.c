/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movebot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 07:06:44 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 07:11:52 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	move_bot2(int i, int j, int **tab)
{
	int save;

	save = tab[i][j];
	tab[i][j] = 0;
	while (tab[i][j] == 0 && i < 3)
		i++;
	if (tab[i][j] == save)
		tab[i][j] *= 2;
	else if (tab[i][j] != save && tab[i][j] != 0)
		tab[i - 1][j] = save;
	else
		tab[i][j] = save;
}

void		move_bot(int **tab)
{
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 3;
		while (i >= 0)
		{
			if (tab[i][j] != 0)
			{
				move_bot2(i, j, tab);
			}
			i--;
		}
		j++;
	}
}
