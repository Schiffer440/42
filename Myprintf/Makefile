# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adugain <adugain@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 11:07:09 by adugain           #+#    #+#              #
#    Updated: 2022/12/06 17:55:16 by adugain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c format.c

CFLAGS	= -Wextra -Wall -Werror

OBJ = $(SRC:.c=.o)

$(NAME): 
	gcc $(CFLAGS) -c $(SRC) -I ../ft_printf.h
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJB)

fclean: clean
	rm -f *.a

re: fclean all

.PHONY: all clean fclean re
