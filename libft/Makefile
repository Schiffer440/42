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

SRC	= $(wildcard src/*.c src2/*.c) \
		main/main.c
SRC2 = $(wildcard src2/*.c) \
		main/main2.c
SRC2 = $(wildcard src2/*.c) \
		main/main1.c

CFLAGS	= -Wextra -Wall -Werror

NAME	= TEST

NAME1	= TEST1

NAME2	= TEST2

INC = -I inc/libft.h

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

go: $(OBJ) $(OBJ2) arch
	clear
	cc -o $(NAME)  $(OBJ) $(INC) $(CFLAGS) -lbsd -g3
	cc -o $(NAME1)  $(OBJ2) $(INC) $(CFLAGS) -lbsd -g3
	cc -o $(NAME2)  $(OBJ2) $(INC) $(CFLAGS) -lbsd -g3
	
arch:
	ar -rcs libft.a $(OBJ)
clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)
fclean: clean
	rm -f $(NAME)
	rm -f $(NAME1)
	clear

re: fclean go