/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvede <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:02:16 by amedvede          #+#    #+#             */
/*   Updated: 2018/09/19 17:09:06 by amedvede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_PRINTF_H
# define B_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_mystruct
{
	int				number;
	char			*str;
	unsigned int	unsnumber;
	void			*ptr;
	int				strlen;
}					t_mystruct;

void				choose_chr_str(t_mystruct *datastruct, char c, va_list arg);
void				choose_d_i(t_mystruct *datastruct, va_list arg);
void				choose_o_x_p(t_mystruct *datastruct, char c, va_list arg);
void				choose_u(t_mystruct *datastruct, va_list arg);
void				putobject(t_mystruct *datastruct,
					const char *restrict traverse, int i, va_list arg);
size_t				ft_strlen(const char *str);
int					skip(const char *restrict traverse,
					int i, t_mystruct *datastruct);
int					b_printf(const char *restrict format, ...);
void				putnbr(int nbr, t_mystruct *datastruct);
void				putunsignedint(unsigned int nbr, t_mystruct *datastruct);
void				putstr(char *str);
char				*convert(unsigned long long nbr, int base);

#endif
