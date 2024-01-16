/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:40:31 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/16 13:48:34 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	final_order(t_list **stack)
{
	t_list	*lower_node;
	int		size;

	size = ft_listsize(stack);
	lower_node = ft_min_max(stack, 0);
	while (lower_node->position != 0)
	{
		if (lower_node->position <= size / 2)
			rotate_a(stack);
		else
			reverse_rotate_a(stack);
	}
}

void	ft_sort_2(t_list **stack_a)
{
	t_list	*current;
	t_list	*next;

	current = *stack_a;
	next = current->next;
	if (current->value > next->value)
		return (swap_a(stack_a));
	else
		return ;
}

void	ft_sort_3(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	while (!ft_verify_sort(stack_a))
	{
		first = *stack_a;
		second = first->next;
		third = second->next;
		if (first->value > third->value)
			rotate_a(stack_a);
		else if (first->value > second->value)
			swap_a(stack_a);
		else if (first->value < second->value && first->value < third->value)
		{
			swap_a(stack_a);
			rotate_a(stack_a);
		}
	}
}

void	ft_sort_5(t_list **s_a, t_list **s_b)
{
	t_list	*node;

	push_b(s_a, s_b, 1);
	push_b(s_a, s_b, 1);
	ft_sort_3(s_a);
	if ((*s_b)->value < (*s_b)->next->value)
		swap_b(s_b);
	while (*s_b)
	{
		edit_list_costs(s_a, s_b);
		set_targets(s_a, s_b);
		node = *s_b;
		move_node_a(s_a, s_b, node);
	}
}

void	ft_sort_big(t_list **s_a, t_list **s_b)
{
	int	chunk_nb;

	if (ft_listsize(s_a) <= 100)
		chunk_nb = 1;
	else
		chunk_nb = 5;
	assign_chunk_nb(s_a, chunk_nb);
	calc_cost_first_pos(s_a);
	calc_cost_first_pos(s_b);
	push_chunks_b(s_a, s_b, chunk_nb);
	ft_sort_3(s_a);
	edit_list_costs(s_a, s_b);
	sort_stack_pusha(s_a, s_b, chunk_nb);
}

