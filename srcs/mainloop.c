/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 07:06:32 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 15:32:31 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		mainloop(int **tab, int win, int score)
{
	int		nbr;
	int		ret;

	while (1)
	{
		if ((win = setwin(tab, score, win)) == -1)
			return (-1);
		if (win == -2)
			return (-2);
		printboard(tab, win, score);
		nbr = getch();
		while (nbr != 27 && nbr != KEY_LEFT && nbr != KEY_RIGHT && nbr != KEY_UP
				&& nbr != KEY_DOWN && nbr != KEY_RESIZE && nbr != 10)
		{
			printusage();
			nbr = getch();
		}
		if (nbr == KEY_RESIZE)
			continue ;
		if ((ret = checkkey(tab, nbr, &score)))
			return (ret);
	}
}
