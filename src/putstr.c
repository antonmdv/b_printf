/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 21:38:24 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/18 21:38:47 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

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
