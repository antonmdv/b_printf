/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putobject.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 21:41:49 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/19 17:02:46 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

void	putobject(t_mystruct *datastruct,
		const char *restrict traverse, int i, va_list arg)
{
	char special;

	special = '\%';
	if (traverse[i] == 'c' || traverse[i] == 's')
		choose_chr_str(datastruct, traverse[i], arg);
	else if (traverse[i] == 'd' || traverse[i] == 'i')
		choose_d_i(datastruct, arg);
	else if (traverse[i] == 'o' || traverse[i] == 'x' || traverse[i] == 'p')
		choose_o_x_p(datastruct, traverse[i], arg);
	else if (traverse[i] == 'u')
		choose_u(datastruct, arg);
	else if (traverse[i] == '%')
	{
		write(1, &special, 1);
		datastruct->strlen += 1;
	}
}
