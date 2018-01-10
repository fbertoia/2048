/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printrules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 07:07:03 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 07:09:49 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	printmenu(void)
{
	clear();
	attron(COLOR_PAIR(15));
	mvprintw(LINES / 2 - 5, COLS / 2 - 10, "Welcome to 2048 !");
	mvprintw(LINES / 2 - 2, COLS / 2 - 10, "1)   Rules");
	mvprintw(LINES / 2 - 1, COLS / 2 - 10, "2)   Play 4 * 4");
	mvprintw(LINES / 2, COLS / 2 - 10, "3)   Leave");
	mvprintw(LINES / 2 + 4, COLS / 2 - 10,
			"%d is the win condition.", WIN_VALUE);
	attroff(COLOR_PAIR(15));
	refresh();
}
