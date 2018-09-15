/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:02:16 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/14 17:39:48 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_PRINTF_H
# define B_PRINTF_H
# include <unistd.h>

void b_printf(const char * restrict format,...);
void putnbr(int nbr);
void putunsignedint(unsigned int nbr);
void putstr(char *str);
char *convert(unsigned int nbr, int base);
char *getaddress(unsigned long long int value, int base);
#endif
