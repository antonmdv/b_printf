/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 21:39:16 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/19 17:08:19 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

void	putunsignedint(unsigned int nbr, t_mystruct *datastruct)
{
	if (nbr >= 10)
	{
		putunsignedint(nbr / 10, datastruct);
		putunsignedint(nbr % 10, datastruct);
	}
	if (nbr < 10)
		putnbr(nbr, datastruct);
}
