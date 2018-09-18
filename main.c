/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:17:49 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/18 12:48:57 by amedvede         ###   ########.fr       */
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
	unsigned int hex = 256;
	

	/*	
	 * Add return int to b_printf
	 * Skip %       d
	 * Errors?
	*/
	//char *str = "str bitch";
	//unsigned int unnum = -42;

int a =	printf(" char: %c\n str: %s\n int(d): %d\n int(i): %i\n unsigned int: %u\n octal: %o\n hex: %x\n pointer: %p ", c, str, num, num, unnum, oct, hex, &str);
	//int a = printf(" char: %c\n", 'a');
	//int a = printf(" digit: %i\n", 20);
	//int a = printf(" ptr: %p\n", &str);
	//int a = printf(" uns: %u\n", unnum);
	//int a = printf(" char: %c\n", 'a');
	
	printf("\n\n");
		
	//int b = b_printf(" char: %c\n", 'a');
	//int b = b_printf(" char: %s\n", "STR ");
	//int b = b_printf(" digit: %i\n", 20);
	//int b = b_printf(" octal: %o\n", 256);
	//int b = b_printf(" hex: %x\n", 256);
	//int b = b_printf(" ptr: %p\n", &str);
	//int b = b_printf(" uns: %u\n", unnum);
int b = b_printf(" char: %c\n str: %s\n int(d): %d\n int(i): %i\n unsigned int: %u\n octal: %o\n hex: %x\n pointer: %p ", c, str, num, num, unnum, oct, hex, &str);
//	b_printf("HELLO %s %s", "HI", "HOLA");

printf("\n\n\na = %d\tb = %d\n\n",a,b);
	//printf("\n\n");
	
	/*
	char *str = "STRING";
	int num = 10;	
	char ch = 'a';
	*/
	
	//unsigned int dbnum = -10;
	
	//char *str = "Privet";
	
	//unsigned int un = -2;
	//printf("\nUN: %p\n", &str);
	
	//b_printf("\n\n%d\t%d\n\n\n",5,6);
	
	//printf("\nPRINTF:%  x\t",256 , "%x\n\n", 300);
	//b_printf("\nBPRINTF:%  x\t",256,"%x\n\n"  300);
	
	//printf("\n\nprintf% d\n\n", 7);
	//b_printf("\n\bprintfn% d", 7);
	

//b_printf("\n\n %o \n", -3);
	//char *c = "abcde";
//	b_printf("hello");

	//error to fix!
	//b_printf("%", "test");
	
	//SKIP %     d
	return (0);
}
