# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amedvede <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 18:11:03 by amedvede          #+#    #+#              #
#    Updated: 2018/09/17 22:21:35 by amedvede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME = libftprintf.a
LIBFILES = b_printf.c src/*.c
OBJFILES = helpers2.o chooser.o b_printf.o helpers.o
COMPILE  = gcc -c -Wall -Werror -Wextra
MAKELIB = ar rc
OPTIMIZE = ranlib
INCLUDES = -I includes

$(NAME): all

all:
	$(COMPILE) $(LIBFILES) $(INCLUDES)
	$(MAKELIB) $(LIBNAME) $(OBJFILES)
	$(OPTIMIZE) $(LIBNAME)

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(LIBNAME)

re: fclean all

compile:
	gcc -Wall -Werror -Wextra -I includes main.c $(LIBNAME)

q: fclean all compile
