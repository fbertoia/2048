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

static int		checkisfull(int **tab)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int				checklose(int **tab)
{
	if (checkisfull(tab) || checkmove(tab))
		return (0);
	return (1);
}
