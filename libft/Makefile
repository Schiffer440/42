# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adugain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:45:28 by adugain           #+#    #+#              #
#    Updated: 2022/11/07 11:45:43 by adugain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= $(wildcard ft_*.c/*.c) \
		main/main.c
SRC2	= $(wildcard ft_*.c/*.c) \
		main/main2.c



CFLAGS	= -Wextra -Wall -Werror

NAME	= TEST

NAME2	= TEST2

INC = -I inc/libft.h

OBJ = $(SRC:.c=.o)
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

	
so: $(OBJ)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

go: $(OBJ) $(OBJ2) arch
	clear
	cc -o $(NAME)  $(OBJ) $(INC) $(CFLAGS) -lbsd
	cc -o $(NAME2)  $(OBJ2) $(INC) $(CFLAGS) -lbsd
	
arch:
	ar -rcs libft.a $(OBJ)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME1)
	rm -f $(NAME2)
	clear

re: fclean go