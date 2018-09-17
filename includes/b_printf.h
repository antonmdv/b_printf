/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:02:16 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/16 17:01:20 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_PRINTF_H
# define B_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

typedef struct		mystruct
{
	int				number;
	char *			str;
	unsigned int	unsnumber;
	void *			ptr;
	char *			mystring;
}					mystruct;

void	b_printf(const char * restrict format,...);
void	putnbr(int nbr);
void	putunsignedint(unsigned int nbr);
void	putstr(char *str);
char	*convert(unsigned int nbr, int base);
char	*getaddress(unsigned long long int value, int base);

#endif
