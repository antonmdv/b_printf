/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 21:42:54 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/19 17:03:17 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

int		skip(const char *restrict traverse, int i, t_mystruct *datastruct)
{
	while (traverse[i] != '%' && traverse[i])
	{
		write(1, &traverse[i], 1);
		datastruct->strlen++;
		i++;
	}
	return (i);
}
