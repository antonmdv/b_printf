# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amedvede <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 18:11:03 by amedvede          #+#    #+#              #
#    Updated: 2018/09/13 13:04:00 by amedvede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME = libftprintf.a
LIBFILES = b_printf.c
OBJFILES = b_printf.o
COMPILE  = gcc -c -Wall -Werror -Wextra
MAKELIB = ar rc
OPTIMIZE = ranlib

$(NAME): all

all:
	$(COMPILE) $(LIBFILES)
	$(MAKELIB) $(LIBNAME) $(OBJFILES)
	$(OPTIMIZE) $(LIBNAME)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(LIBNAME)

re: fclean all

compile:
	gcc -Wall -Werror -Wextra -I b_printf.h main.c $(LIBNAME)
