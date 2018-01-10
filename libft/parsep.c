/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 02:42:36 by bteissei          #+#    #+#             */
/*   Updated: 2017/05/10 03:04:51 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tf_printf.h"

int		parsep(t_sides *sides, va_list ap)
{
	sides->longueur = 2;
	sides->attributs->diese = 1;
	if (!(parsex(sides, ap, 2)))
		return (0);
	return (1);
}
