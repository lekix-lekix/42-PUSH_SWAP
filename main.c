/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:12:58 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/26 18:11:13 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_stack_pusha(t_list **s_a, t_list **s_b, int nb)
{
	t_list	*node;

	while (*s_b)
	{
		node = select_best_node(s_b, nb);
		move_node_a(s_a, s_b, node);
		edit_list_costs(s_a, s_b);
		if (is_chunk_done(s_b, nb))
			nb--;
	}
}

void	pick_an_algo(t_list **s_a, t_list **s_b, int nb)
{
	assign_index(s_a);
    // print_list(s_a);
	if (nb == 2)
		ft_sort_2(s_a);
	else if (nb == 3)
		ft_sort_3(s_a);
	else if (nb == 4)
		ft_sort_4(s_a, s_b);
	else if (nb == 5)
		ft_sort_5(s_a, s_b);
	else
		ft_sort_big(s_a, s_b);
	final_order(s_a);
}

// void    print_list(t_list **stack)
// {
//     t_list *current;

//     current = *stack;
//     while (current)
//     {
//         printf("current %d index %d\n", current->value, current->index);
//         current = current->next;
//     }
// }

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		malloc_args;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	malloc_args = 0;
	argv = args_checker(&argc, argv, &malloc_args);
	if (!argv)
		return (ft_print_error());
	stack_a = init_stack(argc, argv, &malloc_args);
	if (!stack_a)
		return (ft_print_error());
	stack_b = NULL;
	if (malloc_args)
		ft_free_tab(argv);
	if (ft_verify_sort(&stack_a))
	{
		ft_free_lst(&stack_a);
		return (0);
	}
	pick_an_algo(&stack_a, &stack_b, argc);
    // print_list(&stack_a);
	ft_free_lst(&stack_a);
	return (0);
}
