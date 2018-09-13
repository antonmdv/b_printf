/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:17:49 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/13 13:39:26 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "b_printf.h"
int main(void)
{
	//printf();
	//printf("");
	//printf("HELLO");
	//printf("HELLO %s", "HI", "HOLA");
	//printf("HELLO %s %s", "HI", "HOLA");
	char *str = "STRING";
	int num = 10;	
	b_printf("Number: %d + String: %s",num,str);
		
	return (0);
}
