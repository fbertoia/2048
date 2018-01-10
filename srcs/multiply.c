/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <bteissei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 02:29:07 by bteissei          #+#    #+#             */
/*   Updated: 2018/01/07 07:38:30 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static	int		power2(int nbr)
{
	int i;
	int result;

	result = 1;
	i = 0;
	while (i < nbr)
	{
		result = (result * 2);
		i++;
	}
	return (result);
}

int				multiply22(int nbr, int taille)
{
	int i;

	i = 1;
	while (i < power2(taille) + 1)
	{
		if (nbr == power2(i))
			return (0);
		i++;
	}
	return (1);
}
