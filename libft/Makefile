# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haristot <haristot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 16:20:49 by haristot          #+#    #+#              #
#    Updated: 2021/02/27 19:25:48 by haristot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Wextra -Werror

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = libft.h

OPTION = -c -I $(HEADER)

SRC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c	ft_isdigit.c\
	ft_isprint.c ft_itoa.c ft_memccpy.c	ft_memchr.c	ft_memcmp.c	ft_memcpy.c	ft_memmove.c\
	ft_memset.c	ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
	ft_strchr.c	ft_strdup.c	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c	ft_substr.c	ft_tolower.c ft_toupper.c\
	ft_isprint_s.c get_next_line.c ft_strcpy.c ft_malloc_count.c ft_strdup_n.c ft_error.c\
	

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) $(HEADER)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all