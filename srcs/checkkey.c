/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkkey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 07:05:42 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 14:51:09 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		checkkey(int **tab, int nbr, int *score)
{
	int	**savetab;

	if (nbr == 27)
		return (-2);
	else if (nbr == 10)
		return (1);
	if (!(savetab = duptab(tab)))
		return (-1);
	if (nbr == KEY_UP)
		move_top(tab);
	else if (nbr == KEY_RIGHT)
		move_right(tab);
	else if (nbr == KEY_DOWN)
		move_bot(tab);
	else if (nbr == KEY_LEFT)
		move_left(tab);
	if (checkdiff(tab, savetab))
	{
		fillfirst(tab);
		(*score)++;
	}
	freeoldtab(savetab);
	savetab = NULL;
	return (0);
}
