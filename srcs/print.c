/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:04:12 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 15:17:35 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	getcolor(int tab)
{
	if (tab == 0 || tab == 2)
		return (tab == 0 ? 2 : 4);
	else if (tab == 4)
		return (3);
	else if (tab == 8)
		return (5);
	else if (tab == 16)
		return (6);
	else if (tab == 32)
		return (7);
	else if (tab == 64)
		return (8);
	else if (tab == 128)
		return (9);
	else if (tab == 256)
		return (10);
	else if (tab == 512)
		return (11);
	else if (tab == 1024)
		return (12);
	else if (tab == 2048)
		return (13);
	else
		return (14);
}

static void	print1(int lines, int col)
{
	int		i;
	char	line[100000];

	i = 0;
	while (i < col)
		line[i++] = ' ';
	line[i] = 0;
	i = 0;
	attron(COLOR_PAIR(1));
	while (i <= lines)
		mvprintw(2 + i++, 2, "%s", line);
	attroff(COLOR_PAIR(1));
}

static void	printnumber(int tab, int printlines, int printcol, int col)
{
	char	*nb;
	char	fill[100000];
	int		i[3];

	i[0] = 0;
	i[1] = (((LINES - 14) / 4) - (((LINES - 14) / 4) % 2 ? 0 : 1));
	while (i[0] < col)
		fill[i[0]++] = ' ';
	fill[i[0]] = 0;
	i[0] = 0;
	nb = ft_itoa(tab, 10);
	i[2] = ft_strlen(nb);
	attron(COLOR_PAIR(getcolor(tab)));
	attron(A_BOLD);
	while (i[0] < i[1])
	{
		if (i[0] + 1 == (i[1] / 2 + 1))
			mvprintw(printlines + i[0]++, printcol, "%*s%-*s", col - (i[2] +
			col / 2 - (i[2] / 2 + i[2] % 2)), "", i[2] + col / 2 - (i[2] / 2
			+ i[2] % 2), tab ? nb : "");
		else
			mvprintw(printlines + i[0]++, printcol, "%s", fill);
	}
	attroff(COLOR_PAIR(getcolor(tab)));
	free(nb);
}

static void	printtab(int **tab, int lines, int col)
{
	int i;
	int j;
	int printlines;
	int printcol;

	printlines = 3;
	i = 0;
	while (i < 4)
	{
		j = 0;
		printcol = 4;
		while (j < 4)
		{
			printnumber(tab[i][j], printlines, printcol, col);
			printcol += col + 2;
			j++;
		}
		printlines += 1 + (lines - (lines % 2 ? 0 : 1));
		i++;
	}
}

void		printboard(int **tab, int win, int score)
{
	int lines;
	int col;

	lines = (LINES - 14) / 4;
	col = (COLS - 14) / 4;
	clear();
	if (!check_screen())
		return ;
	print1(4 + ((lines - (lines % 2 ? 0 : 1)) * 4), 10 + col * 4);
	printtab(tab, lines, col);
	attron(COLOR_PAIR(15));
	mvprintw(0, COLS / 2 - 5, "Score : %d", score);
	if (win == 1)
	{
		mvprintw(LINES - 6, COLS / 2 - 18,
		"You won. Press Enter twice to return");
		mvprintw(LINES - 5, COLS / 2 - 15, "to main menu, or keep playing.");
	}
	else if (win == -1)
	{
		mvprintw(LINES - 6, COLS / 2 - 14, "You lost. Press Enter once to");
		mvprintw(LINES - 5, COLS / 2 - 10, "return to main menu.");
	}
	mvprintw(LINES - 7, COLS / 2 - 9, "Win condition : %d", WIN_VALUE);
	refresh();
}
