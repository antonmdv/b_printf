/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:17:49 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/15 12:25:49 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "b_printf.h"
int main(void)
{
	//printf();
	//b_printf();
	
	//printf("");
	//b_printf("");
	
	char c = 'a';
	char *str = "this is a string";
	int num = 42;
	unsigned int unnum = -42;
	unsigned int oct = 10;
	unsigned int hex = 10;
	
	/*
	 * Add return int to b_printf
	 * Skip %       d
	 * Errors?
	 */

	printf(" char: %c\n str: %s\n int(d): %d\n int(i): %i\n unsigned int: %u\n octal: %o\n hex: %x\n pointer: %p ", c, str, num, num, unnum, oct, hex, &str);

	printf("\n\n");

	b_printf(" char: %c\n str: %s\n int(d): %d\n int(i): %i\n unsigned int: %u\n octal: %o\n hex: %x \n pointer: %p", c, str, num, num, unnum, oct, hex, &str);
	//b_printf("HELLO %s %s", "HI", "HOLA");
	
	/*
	char *str = "STRING";
	int num = 10;	
	char ch = 'a';

	*/
//	unsigned int dbnum = -10;
	
	//char *str = "Privet";
	/*
	 * unsigned int un = -2;
	printf("\nUN: %p\n", &str);
	b_printf("\nadrs: %p\n",&str);
	*/

	b_printf("\n\n%o\n", -3);	
	return (0);
}
