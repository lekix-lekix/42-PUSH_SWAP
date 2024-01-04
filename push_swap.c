/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:08:51 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/04 16:41:07 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_verify_sort(t_list **stack)
{
	t_list	*current;
	t_list	*next;

	current = *stack;
	while (current->next)
	{
		next = current->next;
		if (current->value > next->value)
			return (0);
		current = current->next;
	}
	return (1);
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

t_list	*ft_min_max(t_list **stack, int min_or_max)
{
	t_list	*current;
	t_list  *min_max;

	current = *stack;
	min_max = current;
	while (current)
	{
        if (!min_or_max && current->value < min_max->value)
            min_max = current;
        else if (min_or_max && current->value > min_max->value)
            min_max = current;
        current = current->next;
	}
	return (min_max);
}

t_list	*ft_find_last(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current->next)
		current = current->next;
	return (current);
}

void	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	int	lst_size;

	lst_size = ft_lstsize(stack_a);
	if (!lst_size || lst_size == 1)
		return ;
	if (lst_size == 2)
	{
		(void)stack_b;
		return (ft_sort_2(stack_a));
	}
	if (lst_size == 3)
		return (ft_sort_3(stack_a));
	// if (lst_size == 5)
	// 	return (ft_sort_5(stack_a, stack_b));
}
