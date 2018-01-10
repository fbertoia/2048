/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2048.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 07:06:25 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 15:17:40 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		main_2048(void)
{
	int			**tab;
	void		*win;
	int			nb;
	int			stock;

	nb = 0;
	win = initscr();
	noecho();
	keypad(win, 1);
	if (!(tab = initboard()))
		return (1);
	if ((stock = mainloop(tab, 0, 0)) == 1)
	{
		while (nb != 10 && nb != 27)
			nb = getch();
	}
	freeoldtab(tab);
	endwin();
	if (stock == -2)
		return (0);
	return (1);
}
