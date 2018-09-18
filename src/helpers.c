/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:29:11 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/18 14:02:34 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

void	putnbr(int nbr, mystruct *datastruct)
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

void	putunsignedint(unsigned int nbr, mystruct *datastruct)
{
	if (nbr >= 10)
	{
		putunsignedint(nbr / 10, datastruct);
		putunsignedint(nbr % 10, datastruct);
	}
	if (nbr < 10)
		putnbr(nbr, datastruct);
}

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*convert(unsigned int num, int base)
{
	static char representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	while (num != 0)
	{
		*(--ptr) = representation[num % base];
		num /= base;
	}
	return (ptr);
}

char	*getaddress(unsigned long long int value, int base)
{
	char					*nstr;
	static char				str;
	unsigned long long int	tmp;
	char					*basetab;

	basetab = "0123456789abcdef";
	nstr = &str;
	tmp = value;
	while (tmp)
	{
		*--nstr = basetab[tmp % base];
		tmp /= base;
	}
	return (nstr);
}
