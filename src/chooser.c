/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chooser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:16:52 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/19 17:02:13 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

void	choose_chr_str(t_mystruct *datastruct, char c, va_list arg)
{
	if (c == 'c')
	{
		datastruct->number = va_arg(arg, int);
		write(1, &datastruct->number, 1);
		datastruct->strlen++;
	}
	else if (c == 's')
	{
		datastruct->str = va_arg(arg, char *);
		if (datastruct->str != NULL)
		{
			putstr(datastruct->str);
			datastruct->strlen += ft_strlen(datastruct->str);
		}
		else
		{
			putstr("(null)");
			datastruct->strlen += ft_strlen("(null)");
		}
	}
}

void	choose_d_i(t_mystruct *datastruct, va_list arg)
{
	datastruct->number = va_arg(arg, int);
	putnbr(datastruct->number, datastruct);
}

void	choose_o_x_p(t_mystruct *datastruct, char c, va_list arg)
{
	if (c == 'o' || c == 'x')
		datastruct->unsnumber = va_arg(arg, unsigned int);
	else
		datastruct->ptr = va_arg(arg, void *);
	if (c == 'o')
		datastruct->str = convert(datastruct->unsnumber, 8);
	else if (c == 'x')
		datastruct->str = convert(datastruct->unsnumber, 16);
	else if (c == 'p')
	{
		datastruct->str = convert((unsigned long long)datastruct->ptr, 16);
		putstr("0x");
		datastruct->strlen += ft_strlen("0x");
	}
	putstr(datastruct->str);
	datastruct->strlen += ft_strlen(datastruct->str);
}

void	choose_u(t_mystruct *datastruct, va_list arg)
{
	datastruct->unsnumber = va_arg(arg, unsigned int);
	putunsignedint(datastruct->unsnumber, datastruct);
}
