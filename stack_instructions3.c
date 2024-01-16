/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:28:13 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/16 14:06:17 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp;
    int     lst_size;

    lst_size = ft_listsize(stack); 
	if (!*stack || !lst_size || lst_size == 1)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	if (!*stack)
		return ;
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

	if (!*stack)
		return ;
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

void	push_a(t_list **stack_a, t_list **stack_b, int print)
{
	t_list	*head_a;
	t_list	*head_b;

	if (!*stack_b)
		return ;
	head_b = *stack_b;
	*stack_b = (*stack_b)->next;
	if (!*stack_a)
	{
		*stack_a = head_b;
        (*stack_a)->position = 0;
		(*stack_a)->next = NULL;
	}
	else
	{
		head_a = *stack_a;
		*stack_a = head_b;
		(*stack_a)->next = head_a;
	}
    recalculate_position(stack_a);
    recalculate_position(stack_b);
    if (print)
	    ft_printf("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b, int print)
{
	t_list	*head_a;
	t_list	*head_b;

	if (!*stack_a)
		return ;
	head_a = *stack_a;
	*stack_a = (*stack_a)->next;
	if (!*stack_b)
	{
		*stack_b = head_a;
        head_a->position = 0;
		head_a->next = NULL;
	}
	else
	{
		head_b = *stack_b;
		*stack_b = head_a;
		(*stack_b)->next = head_b;
	}
    recalculate_position(stack_a);
    recalculate_position(stack_b);
    if (print)
	    ft_printf("pb\n");
}

