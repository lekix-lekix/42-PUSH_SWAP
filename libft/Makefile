# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 14:33:33 by lekix             #+#    #+#              #
#    Updated: 2023/12/27 13:42:35 by kipouliq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalnum.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_strlen.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_atoi.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strdup.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_putnbr_fd.c \
		ft_substr.c \
		ft_itoa.c \
		ft_bzero.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_calloc.c \
		ft_strjoin.c \
		ft_split.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_memmove.c \
		ft_strtrim.c \

MAIN = main.c

OBJS = $(SRCS:.c=.o)

CC = cc

INCLUDE = -I .

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	
clean:
	rm -f *.o

fclean: clean
	rm -f libft.a

re: fclean
	make all

.PHONY: all clean fclean re bonus