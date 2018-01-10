/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setwin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 07:07:09 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 15:31:46 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		setwin(int **tab, int score, int alreadywin)
{
	int nb;

	nb = 0;
	if (checklose(tab))
	{
		printboard(tab, -1, score);
		while (nb != 10 && nb != 27 && nb != KEY_RESIZE)
			nb = getch();
		if (nb == 10)
			return (-1);
		if (nb == KEY_RESIZE)
			setwin(tab, score, alreadywin);
		return (-2);
	}
	if (checkwin(tab))
		return (1);
	return (alreadywin);
}
