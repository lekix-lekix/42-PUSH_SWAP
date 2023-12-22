/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:28:13 by kipouliq          #+#    #+#             */
/*   Updated: 2023/12/22 18:02:14 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	tmp = *stack;
	*stack = (*stack)->next;
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*current;
	t_list	*head;
	t_list	*prev;

	head = *stack;
	current = *stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	*stack = current;
	(*stack)->next = head;
	prev->next = NULL;
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;

	if (!(*stack_b))
		return ;
	head_b = *stack_b;
	*stack_b = (*stack_b)->next;
	if (!(*stack_a))
	{
		*stack_a = head_b;
		head_b->next = NULL;
	}
	else
	{
		head_a = *stack_a;
		*stack_a = head_b;
		(*stack_a)->next = head_a;
	}
	ft_printf("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;

	if (!(*stack_a))
		return ;
	head_a = *stack_a;
	*stack_a = (*stack_a)->next;
	if (!(*stack_b))
	{
		*stack_b = head_a;
		head_a->next = NULL;
	}
	else
	{
		head_b = *stack_b;
		*stack_b = head_a;
		(*stack_b)->next = head_b;
	}
	ft_printf("pb\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (!args_checker(argc, argv))
    {
        printf("ERROR\n");
		return (-1);
    }
	stack_a = init_stack(argc, argv);
	stack_b = NULL;
	ft_print_lst(&stack_a, &stack_b, argc - 1);
    swap_b(&stack_b);
	ft_print_lst(&stack_a, &stack_b, argc - 1);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}

// SIGSEV avec 1 / 0 element