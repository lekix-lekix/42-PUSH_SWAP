/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:15:14 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/08 13:46:29 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdio.h> // to remove
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				position;
    int             index;
	int				cost;
    int             chunk_nb;
	struct s_list	*target_node;
	struct s_list	*next;
}					t_list;

void				swap(t_list **stack);
void				rotate(t_list **stack);
void				reverse_rotate(t_list **stack);
void				push_a(t_list **stack_a, t_list **stack_b);
void				push_b(t_list **stack_a, t_list **stack_b);
void				swap_a(t_list **stack);
void				swap_b(t_list **stack);
void				swap_both(t_list **s_a, t_list **s_b);
void				rotate_a(t_list **stack);
void				rotate_b(t_list **stack);
void				rotate_both(t_list **s_a, t_list **s_b);
void				reverse_rotate_a(t_list **stack);
void				reverse_rotate_b(t_list **stack);
void				reverse_rotate_both(t_list **s_a, t_list **s_b);
void				ft_push_swap(t_list **stack_a, t_list **stack_b);
t_list				*init_stack(int argc, char **args);
t_list				*ft_lstnew(int nb, int pos);
void				ft_lstadd_back(t_list **stack, t_list *new_node);
t_list				*init_stack(int argc, char **args);
void				ft_free_stack(t_list **stack);
void				ft_print_lst(t_list **stack_a, t_list **stack_b, int elems);
char				**args_checker(int argc, char **args);
int					ft_lstsize(t_list **lst);
t_list				*ft_min_max(t_list **stack, int min_or_max);
void				recalculate_position(t_list **stack);
int					find_node_position(t_list **stack, int nb);
t_list				*find_target_node_pos(t_list **stack, t_list *node);
void				edit_cost_target(t_list **s_a, t_list **s_b, t_list *node);
void				ft_sort_3(t_list **stack_a);

#endif