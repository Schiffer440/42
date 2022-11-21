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

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		ft_tolower.c ft_toupper.c \

CFLAGS	= -Wextra -Wall -Werror

NAME	= TEST

NAME2	= TEST2

OBJ = $(SRC:.c=.o)

so: $(OBJ)
	gcc -nostartfiles -shared -o libft.so $(OBJ)
	
all: $(OBJ) $(OBJ2) arch
	gcc $(CFLAGS) -o $(OBJ)
	
arch:
	ar -rcs libft.a $(OBJ)
clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
	rm -f *.a

re: fclean all