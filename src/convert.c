/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 21:37:35 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/19 17:02:29 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

char	*convert(unsigned long long num, int base)
{
	char	*representation;
	char	*buffer;
	char	*ptr;

	representation = "0123456789abcdef";
	buffer = malloc(sizeof(char) * 64);
	ptr = &buffer[sizeof(buffer) / sizeof(buffer[0])];
	while (num != 0)
	{
		*(--ptr) = representation[num % base];
		num /= base;
	}
	return (ptr);
}
