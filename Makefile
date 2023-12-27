# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 12:11:49 by kipouliq          #+#    #+#              #
#    Updated: 2023/12/27 17:23:49 by kipouliq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = make_stack.c \
		list_functions.c \
		list_functions2.c \
		stack_instructions.c \
		stack_instructions2.c \
		args_parsing.c \
		args_parsing2.c \
		push_swap.c

OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -g

PATH_LIBFT = ./libft

PATH_FTPRINTF = ./ft_printf

LIBFT = ./libft.a

LIBFTPRINTF = ./libftprintf.a

all : bonus

$(NAME) : $(OBJ)
	make -C $(PATH_LIBFT)
	make -C $(PATH_FTPRINTF)
	cp ./libft/libft.a ./libft.a
	cp ./ft_printf/libftprintf.a ./libftprintf.a
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(LIBFTPRINTF) -o $(NAME) -g3

bonus : $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -I $(PATH_LIBFT) -o $@

clean :
	make -sC $(PATH_LIBFT) clean
	rm -f *o

fclean : clean
	make -sC $(PATH_LIBFT) fclean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all bonus clean fclean re