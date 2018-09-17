/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:17:40 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/16 23:05:23 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "b_printf.h"

/*
char *ft_strnew(size_t size)
{
	char str[size];
	
	return str;
}

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;

	while(str[i])
		i++;
	return i;
}

char *addchar(char * str, char c)
{
	char    *res;
    size_t    size;

    size = ft_strlen(str);
    res = ft_strnew(size + 1);
    if (!res)
        return (NULL);
    ft_strcpy(res, str);
    res[size] = c;
    res[size + 1] = '\0';
    return (res);
}
*/
int		skip(const char *restrict traverse, int i, mystruct datastruct)
{
	while (traverse[i] != '%' && traverse[i])
	{
		write(1, &traverse[i], 1);
		datastruct.str = NULL;
		//datastruct.str=addchar(datastruct.str,traverse[i]);
		i++;
	}
	return (i);
}

void	putobject(mystruct datastruct,
		const char *restrict traverse, int i, va_list arg)
{
	if (traverse[i] == 'c')
	{
		datastruct.number = va_arg(arg, int);
		write(1, &datastruct.number, 1);
	}
	else if (traverse[i] == 'd' || traverse[i] == 'i')
	{
		datastruct.number = va_arg(arg, int);
		putnbr(datastruct.number);
	}
	else if (traverse[i] == 's')
	{
		datastruct.str = va_arg(arg, char *);
		putstr(datastruct.str);
	}
	else if (traverse[i] == 'o')
	{
		datastruct.unsnumber = va_arg(arg, unsigned int);
		datastruct.str = convert(datastruct.unsnumber, 8);
		putstr(datastruct.str);
	}
	else if (traverse[i] == 'x')
	{
		datastruct.unsnumber = va_arg(arg, unsigned int);
		datastruct.str = convert(datastruct.unsnumber, 16);
		putstr(datastruct.str);
	}
	else if (traverse[i] == 'p')
	{
		datastruct.ptr = va_arg(arg, void *);
		datastruct.str = getaddress((unsigned long long int)datastruct.ptr, 16);
		putstr("0x");
		putstr(datastruct.str);
	}
	else if (traverse[i] == 'u')
	{
		datastruct.unsnumber = va_arg(arg, unsigned int);
		putunsignedint(datastruct.unsnumber);
	}
}

void	b_printf(const char *restrict format, ...)
{
	const char *restrict	traverse;
	int						i;
	mystruct				datastruct;
	va_list					arg;

	va_start(arg, format);
	traverse = format;
	datastruct.str = "";
	i = 0;
	while (traverse[i])
	{
		i = skip(traverse, i, datastruct);
		if (traverse[i])
		{
			i++;
			putobject(datastruct, traverse, i, arg);
			i++;
		}
	}
	
	va_end(arg);
}
