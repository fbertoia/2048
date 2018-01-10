/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:44:21 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 07:55:48 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdio.h>
# include <ncurses.h>
# include <stdlib.h>
# include <time.h>
# include <signal.h>
# include "tf_printf.h"

void	printboard(int **tab, int win, int score);
int		checkmove(int **tab);
int		checkkey(int **tab, int nbr, int *score);
int		setwin(int **tab, int score, int alreadywin);
int		checkwin(int **tab);
int		**initboard(void);
int		mainloop(int **tab, int win, int score);
int		checklose(int **tab);
void	fillfirst(int **tab);
void	printusage(void);
int		**duptab(int **oldtab);
int		checkdiff(int **tab, int **oldtab);
void	freeoldtab(int **tab);
int		multiply22(int nbr, int taille);

void	move_top(int **tab);
void	move_bot(int **tab);
void	move_right(int **tab);
void	move_left(int **tab);
void	printmenu(void);
int		printrules(void);
int		main_2048(void);
void	init_colors();
int		check_screen(void);

enum	e_const
{
	WIN_VALUE = 2048
};

#endif
