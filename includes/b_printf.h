/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:02:16 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/17 22:05:10 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_PRINTF_H
# define B_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		mystruct
{
	int				number;
	char *			str;
	unsigned int	unsnumber;
	void *			ptr;
	int				strlen;
}					mystruct;

void choose_chr_str(mystruct *datastruct,char c, va_list arg);
void choose_d_i(mystruct *datastruct, va_list arg);
void choose_o_x(mystruct *datastruct, char c, va_list arg);
void choose_u(mystruct *datastruct, va_list arg);
void	putobject(mystruct *datastruct,const char *restrict traverse, int i, va_list arg);
size_t		ft_strlen(const char *str);
int		skip(const char *restrict traverse, int i, mystruct *datastruct);
int		b_printf(const char * restrict format,...);
void	putnbr(int nbr, mystruct *datastruct);
void	putunsignedint(unsigned int nbr, mystruct *datastruct);
void	putstr(char *str);
char	*convert(unsigned int nbr, int base);
char	*getaddress(unsigned long long int value, int base);

#endif
