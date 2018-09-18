/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:17:40 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/18 14:01:53 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

int	b_printf(const char *restrict format, ...)
{
	const char *restrict	traverse;
	int						i;
	mystruct				datastruct;
	va_list					arg;

	va_start(arg, format);
	traverse = format;
	datastruct.strlen = 0;
	i = 0;
	while (traverse[i])
	{
		i = skip(traverse, i, &datastruct);
		if (traverse[i])
		{
			i++;
			putobject(&datastruct, traverse, i, arg);
			i++;
		}
	}
	va_end(arg);
	return (datastruct.strlen);
}
