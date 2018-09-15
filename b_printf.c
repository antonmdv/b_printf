/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:17:40 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/14 17:45:57 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "b_printf.h"

//change return type to int later
void b_printf(const char * restrict format, ...)
{
	const char * restrict traverse;
	int number;
	unsigned int unsnumber;
	char *str;
	int i;
	void *ptr;

	i = 0;

	//argument initialization
	va_list arg;

	//fills args
	va_start(arg, format);
	
	traverse = format;
	
	//go through the entire "...."
	while (traverse[i])
	{
		//skip untill the first occurence of &
		while(traverse[i] != '%' && traverse[i])
		{
			write(1, &traverse[i] ,1);
			i++;
		}
		if(traverse[i]){
			i++;
			//once % is found go to the next char to determie what data type to output
			if(traverse[i] == 'c')
			{
				number = va_arg(arg, int);
				write(1, &number,1);
			}
			else if(traverse[i] == 'd' || traverse[i] == 'i') 
			{
				number = va_arg(arg, int);
				putnbr(number);
			}
			else if(traverse[i] == 's')
			{
				str = va_arg(arg, char *);
				putstr(str);
			}
			else if(traverse[i] == 'o')
			{
				unsnumber = va_arg(arg, unsigned int);
				str = convert(unsnumber,8);
				putstr(str);		
			}
			else if(traverse[i] == 'x')
			{
				unsnumber = va_arg(arg, unsigned int);
				str = convert(unsnumber, 16);
				putstr(str);
			}
			
			else if(traverse[i] == 'p')
			{
				ptr = va_arg(arg, void *);
				str = getaddress((unsigned long long int)ptr, 16);
				putstr("0x");
				putstr(str);
			}
			
			else if(traverse[i] == 'u')
			{
				unsnumber = va_arg(arg, unsigned int);
				putunsignedint(unsnumber);
			}
			i++;
		}
	}
	va_end(arg);
}
