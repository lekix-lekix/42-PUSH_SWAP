# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 12:11:49 by kipouliq          #+#    #+#              #
#    Updated: 2024/01/16 14:34:07 by kipouliq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRC = list_functions.c \
		list_functions2.c \
		stack_instructions.c \
		stack_instructions2.c \
		stack_instructions3.c \
		args_parsing.c \
		args_parsing2.c \
		main.c \
		sort_functions.c \
		utils.c \
		utils2.c \
		cost_target_functions.c \
		index_chunks_functions.c \
		select_move_nodes.c

SRCS_BONUS = list_functions.c \
		list_functions2.c \
		stack_instructions.c \
		stack_instructions2.c \
		stack_instructions3.c \
		args_parsing.c \
		args_parsing2.c \
		checker_bonus.c

OBJ = $(SRC:.c=.o)

BONUS_OBJS = $(SRCS_BONUS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -g

PATH_LIBFT = ./megalibft

NEW_PATH_LIBFT = .

LIBFT = ./megalibft/megalibft.a

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(PATH_LIBFT)
	# cp ./megalibft/megalibft.a ./megalibft.a
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME) -g3 -v

bonus : $(BONUS_OBJS)
	make -C $(PATH_LIBFT)
	$(CC) $(FLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME_BONUS) -g3 

%.o:%.c
	$(CC) $(FLAGS) -I $(PATH_LIBFT) -c $<  -o $@

clean :
	make -sC $(PATH_LIBFT) clean
	rm -f *o

fclean : clean
	make -sC $(PATH_LIBFT) fclean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all bonus clean fclean re