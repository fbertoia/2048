/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:04:06 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 14:10:00 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	fillfirst(int **tab)
{
	int		tmp;
	int		tmp1;
	int		tmp2;
	time_t	t;

	srand(time((&t)));
	while (1)
	{
		tmp = rand() % 2;
		tmp1 = rand() % 4;
		tmp2 = rand() % 4;
		if (tab[tmp1][tmp2] == 0)
		{
			if (tmp == 0)
				tab[tmp1][tmp2] = 2;
			else
				tab[tmp1][tmp2] = 4;
			break ;
		}
	}
}
