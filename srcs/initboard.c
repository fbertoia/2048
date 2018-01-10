/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initboard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 07:05:59 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 07:37:51 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		**initboard(void)
{
	int i;
	int **tab;

	i = 0;
	if (!(tab = ft_memalloc(sizeof(int*) * 4)))
		return (NULL);
	while (i < 4)
		if (!(tab[i++] = ft_memalloc(sizeof(int) * 4)))
			return (NULL);
	fillfirst(tab);
	fillfirst(tab);
	return (tab);
}
