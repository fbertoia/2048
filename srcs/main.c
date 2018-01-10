/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 02:00:17 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 07:58:27 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <locale.h>

static int	checkenum(void)
{
	if (WIN_VALUE == 1)
	{
		ft_printf("Oui, 1 est une puissance de 2, certes. Mais non. DSL. :D\n");
		return (1);
	}
	if (WIN_VALUE <= 0 || WIN_VALUE >= 2147483647 || multiply22(WIN_VALUE, 4))
	{
		ft_printf("Changez la valeur WIN_VALUE dans le .h, car %d ", WIN_VALUE);
		ft_printf("n'est pas une puissance de 2.\nVous pouvez prendre par exe");
		ft_printf("mple :\n4;\n8;\n16;\n32;\n64;\n128;\n256;\n512;\n...\n");
		return (1);
	}
	return (0);
}

static void	menuloop(void)
{
	int nb;

	attron(COLOR_PAIR(15));
	while (1)
	{
		printmenu();
		nb = 0;
		while (nb != 49 && nb != 50 && nb != 51
				&& nb != 27 && nb != KEY_RESIZE)
			nb = getch();
		if (nb == 27 || nb == 51)
			return ;
		else if (nb == 49 && printrules() == 0)
			return ;
		else if (nb == 50 && main_2048() == 0)
			return ;
	}
	attroff(COLOR_PAIR(15));
}

int			main(void)
{
	void		*window;

	if (checkenum())
		return (0);
	window = initscr();
	start_color();
	noecho();
	init_colors();
	keypad(window, 1);
	menuloop();
	endwin();
	return (0);
}
