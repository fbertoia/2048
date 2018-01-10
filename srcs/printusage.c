/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printusage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 07:07:06 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 15:09:42 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	printusage(void)
{
	mvprintw(LINES - 4, (COLS / 2) - 3, "Usage :");
	mvprintw(LINES - 3, (COLS / 2) - 6, "Arrows : Move");
	mvprintw(LINES - 2, (COLS / 2) - 6, "Escape : exit");
	mvprintw(LINES - 1, (COLS / 2) - 11, "Enter twice : return to menu");
}
