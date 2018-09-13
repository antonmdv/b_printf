/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:17:40 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/13 13:27:21 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void putnbr(int nbr)
{
	char min = '-';
	char num;
	if(nbr < 0)
	{
		nbr *= -1;
		write(1, &min,1);
	}

	if(nbr >= 10)
		putnbr(nbr/10);
	num = (nbr%10) + '0';
	write(1, &num, 1);

}

void putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

//change return type to int later
void b_printf(const char * restrict format, ...)
{
	const char * restrict traverse;
	int number;
	char *str;
	int i;

	i = 0;

	//argument initialization
	va_list arg;

	//fills args
	va_start(arg, format);
	
	traverse = format;
	
	//go through the entire "...."
	while (traverse[i] != '\0')
	{
		//skip untill the first occurence of &
		while(traverse[i] != '%')
		{
			write(1, &traverse[i] ,1);
			i++;
		}
		i++;
		
		//once % is found go to the next char to determie what data type to output
		if(traverse[i] == 'c')
		{
			number = va_arg(arg, int);
			write(1, &number,1);
		}
		else if(traverse[i] == 'd')
		{
			number = va_arg(arg, int);
			putnbr(number);
		}
		else if(traverse[i] == 's')
		{
			str = va_arg(arg, char *);
			putstr(str);
		}
		i++;
	}
	va_end(arg);
}
