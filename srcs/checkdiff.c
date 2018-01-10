/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkdiff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 07:05:31 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 07:10:50 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		checkdiff(int **tab, int **oldtab)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] != oldtab[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
