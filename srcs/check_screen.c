/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:05:45 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 13:49:17 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		check_screen(void)
{
	char *str;

	str = "Resize the screen.";
	if (LINES - 9 < 9 || COLS < 31)
	{
		mvprintw(LINES / 2, COLS / 2 - ft_strlen(str) / 2, "%s", str);
		refresh();
		return (0);
	}
	else
		return (1);
}
