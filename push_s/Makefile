# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adugain <adugain@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 12:23:52 by adugain           #+#    #+#              #
#    Updated: 2023/01/16 12:32:18 by adugain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC = ft_printf.c format.c

CFLAGS	= -Wextra -Wall -Werror

OBJ = $(SRC:.c=.o)

$(NAME): 
	gcc $(CFLAGS) -c $(SRC) -I ../
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJB)

fclean: clean
	rm -f *.a

re: fclean all

.PHONY: all clean fclean re
