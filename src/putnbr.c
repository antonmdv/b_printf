/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 21:39:58 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/19 17:03:36 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

void	putnbr(int nbr, t_mystruct *datastruct)
{
	char min;
	char num;

	min = '-';
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, &min, 1);
		datastruct->strlen++;
	}
	if (nbr >= 10)
		putnbr((nbr / 10), datastruct);
	num = (nbr % 10) + '0';
	write(1, &num, 1);
	datastruct->strlen++;
}
