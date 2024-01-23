/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:15:14 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/23 15:02:47 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./megalibft/megalibft.h"
# include <stdio.h> // to remove
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				position;
	int				index;
	int				cost;
	int				chunk_nb;
	struct s_list	*target_node;
	struct s_list	*next;
}					t_list;

void				swap(t_list **stack);
void				rotate(t_list **stack);
void				reverse_rotate(t_list **stack);
void				push_a(t_list **stack_a, t_list **stack_b, int print);
void				push_b(t_list **stack_a, t_list **stack_b, int print);
void				swap_a(t_list **stack);
void				swap_b(t_list **stack);
void				swap_both(t_list **s_a, t_list **s_b, int print);
void				rotate_a(t_list **stack);
void				rotate_b(t_list **stack);
void				rotate_both(t_list **s_a, t_list **s_b, int print);
void				reverse_rotate_a(t_list **stack);
void				reverse_rotate_b(t_list **stack);
void				reverse_rotate_both(t_list **s_a, t_list **s_b, int print);
t_list				*init_stack(int argc, char **args, int *malloc_args);
char				**args_checker(int *argc, char **args, int *malloc_args);
int					ft_listsize(t_list **lst);
t_list				*ft_min_max(t_list **stack, int min_or_max);
void				recalculate_position(t_list **stack);
int					ft_verify_sort(t_list **stack);
void				ft_sort_2(t_list **stack_a);
void				ft_sort_3(t_list **stack_a);
void				ft_sort_4(t_list **stack_a, t_list **stack_b);
void				ft_sort_5(t_list **s_a, t_list **s_b);
void				move_node_a(t_list **s_a, t_list **s_b, t_list *node);
void				set_targets(t_list **s_a, t_list **s_b);
void				ft_sort_big(t_list **s_a, t_list **s_b);
void				edit_list_costs(t_list **s_a, t_list **s_b);
void				assign_chunk_nb(t_list **s_a, int nb);
void				calc_cost_first_pos(t_list **stack);
void				push_chunks_b(t_list **s_a, t_list **s_b, int nb);
void				sort_stack_pusha(t_list **s_a, t_list **s_b, int nb);
void				assign_index(t_list **stack);
t_list				*ft_free_lst(t_list **stack);
int					calc_distance(int nb1, int nb2);
int					up_or_down(t_list **stack, t_list *node);
int					is_chunk_done(t_list **stack, int chunk_nb);
t_list				*find_closest_index(t_list **stack, t_list *node);
t_list				*select_best_node(t_list **stack, int nb);
void				push_node_b(t_list **s_a, t_list **s_b, t_list *node);
void				final_order(t_list **stack);
int					ft_free_tab(char **tab);
int					str_digits_check(char *str);
int					ft_check_overflow(char *str);
int					ft_strcmp(char *s1, char *s2);
int					ft_print_error(void);
int					ft_exit_msg(int check_op, int sorted);
int					ft_free_tab(char **tab);
void				calc_cost(t_list **s_a, t_list **s_b);
int					ft_full_verify_sort(t_list **s_a, t_list **s_b);
int					ft_verify_stack(t_list **stack, char **args, int *malloc_args);

#endif