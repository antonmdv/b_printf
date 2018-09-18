/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chooser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:16:52 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/18 12:45:10 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

void choose_chr_str(mystruct *datastruct,char c, va_list arg)
{
	if(c == 'c')
	{
		datastruct->number = va_arg(arg, int);
		write(1, &datastruct->number, 1);
		datastruct->strlen++;
	}
	else if(c == 's')
	{
		datastruct->str = va_arg(arg, char *);
		putstr(datastruct->str);
		datastruct->strlen += ft_strlen(datastruct->str);
	}
}
void choose_d_i(mystruct *datastruct, va_list arg)
{
	datastruct->number = va_arg(arg, int);
	putnbr(datastruct->number, datastruct);	
}
void choose_o_x(mystruct *datastruct, char c, va_list arg)
{
	datastruct->unsnumber = va_arg(arg, unsigned int);
	if(c == 'o')
		datastruct->str = convert(datastruct->unsnumber, 8);
	else if(c == 'x')
		datastruct->str = convert(datastruct->unsnumber, 16);	
	putstr(datastruct->str);
	datastruct->strlen += ft_strlen(datastruct->str);
}
void choose_u(mystruct *datastruct, va_list arg)
{
	datastruct->unsnumber = va_arg(arg, unsigned int);
	putunsignedint(datastruct->unsnumber, datastruct);
	//datastruct->strlen += ft_strlen(datastruct->str);
}
