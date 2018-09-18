/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:41:56 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/18 12:42:53 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

int		skip(const char *restrict traverse, int i, mystruct *datastruct)
{
	while (traverse[i] != '%' && traverse[i])
	{
		write(1, &traverse[i], 1);
		datastruct->strlen++;
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	putobject(mystruct *datastruct,const char *restrict traverse, int i, va_list arg)
{
	if (traverse[i] == 'c' || traverse[i] == 's')
		choose_chr_str(datastruct,traverse[i], arg);	
	else if (traverse[i] == 'd' || traverse[i] == 'i')
		choose_d_i(datastruct, arg);	
	else if (traverse[i] == 'o' || traverse[i] == 'x')
		choose_o_x(datastruct, traverse[i], arg);	
	else if (traverse[i] == 'p')
	{
		datastruct->ptr = va_arg(arg, void *);
		datastruct->str = getaddress(
				(unsigned long long int)datastruct->ptr, 16);
		putstr("0x");
		putstr(datastruct->str);
		datastruct->strlen += ft_strlen(datastruct->str)+ft_strlen("0x");
	}
	else if (traverse[i] == 'u')
		choose_u(datastruct, arg);	
}
