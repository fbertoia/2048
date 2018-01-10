/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 04:12:18 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 07:38:35 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	printrules2(void)
{
	char *str;

	str = "Rules";
	mvprintw(LINES / 2 - 5, COLS / 2 - ft_strlen(str) / 2, "%s", str);
	str = "2048 is played on a gray 4x4 grid, with numbered";
	mvprintw(LINES / 2 - 3, COLS / 2 - ft_strlen(str) / 2, "%s", str);
	str = "tiles that slide smoothly when a player moves them";
	mvprintw(LINES / 2 - 2, COLS / 2 - ft_strlen(str) / 2, "%s", str);
	str = "using the four arrow keys. Every turn, a new tile";
	mvprintw(LINES / 2 - 1, COLS / 2 - ft_strlen(str) / 2, "%s", str);
	str = "will randomly appear in an empty spot on the board";
	mvprintw(LINES / 2, COLS / 2 - ft_strlen(str) / 2, "%s", str);
	str = "with a value of either 2 or 4. Tiles slide as far as";
	mvprintw(LINES / 2 + 1, COLS / 2 - ft_strlen(str) / 2, "%s", str);
	str = "possible in the chosen direction until they are stopped";
	mvprintw(LINES / 2 + 2, COLS / 2 - ft_strlen(str) / 2, "%s", str);
	str = "by either another tile or the edge of the grid.";
	mvprintw(LINES / 2 + 3, COLS / 2 - ft_strlen(str) / 2, "%s", str);
	str = "If two tiles of the same number collide while moving,";
	mvprintw(LINES / 2 + 4, COLS / 2 - ft_strlen(str) / 2, "%s", str);
	str = "they will merge into a tile with the total value";
	mvprintw(LINES / 2 + 5, COLS / 2 - ft_strlen(str) / 2, "%s", str);
	str = "of the two tiles that collided.";
	mvprintw(LINES / 2 + 6, COLS / 2 - ft_strlen(str) / 2, "%s", str);
}

int			printrules(void)
{
	int nb;

	nb = 0;
	clear();
	mvprintw(LINES / 2 + 10, COLS / 2 - 12, "PRESS ENTER TO RETURN TO MENU");
	refresh();
	printrules2();
	while (nb != 10 && nb != KEY_RESIZE && nb != 27)
		nb = getch();
	if (nb == KEY_RESIZE)
		printrules();
	if (nb == 27)
		return (0);
	return (1);
}
