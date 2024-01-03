/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:12:58 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/03 18:18:50 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	calc_distance(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb1 - nb2);
	else
		return (nb2 - nb1);
}

t_list	*find_target_node_pos(t_list **stack, t_list *node)
{
	t_list	*current;
	t_list	*closest;
	int		closest_distance;

	current = *stack;
	closest = NULL;
	closest_distance = ft_min_max(stack, 1)->value - ft_min_max(stack,
			0)->value;
	while (current)
	{
		if (node->value > current->value && calc_distance(current->value,
				node->value) < closest_distance)
		{
			closest_distance = calc_distance(current->value, node->value);
			closest = current;
		}
		current = current->next;
	}
	return (closest);
}

int	up_or_down(t_list **stack, t_list *node)
{
	int	size;

	size = ft_lstsize(stack);
	if (node->position == 0)
		return (-1);
	if ((size % 2 == 0 && node->position < size / 2) || (size % 2 != 0
			&& node->position <= size / 2))
		return (1);
	else
		return (0);
}

void	calc_cost(t_list *node, t_list **s_a, t_list **s_b)
{
	int		size_a;
	int		size_b;
	t_list	*target;

	size_a = ft_lstsize(s_a);
	size_b = ft_lstsize(s_b);
	target = node->target_node;
	if (up_or_down(s_a, node))
		node->cost += node->position;
	else
		node->cost += size_a - node->position;
	if (up_or_down(s_b, target))
		node->cost += target->position;
	else
		node->cost += size_b - target->position;
}

void	edit_cost_target(t_list **s_a, t_list **s_b, t_list *node)
{
	t_list	*min;
	t_list	*max;

	min = ft_min_max(s_b, 0);
	max = ft_min_max(s_b, 1);
	node->cost = 0;
	if (node->value < min->value || node->value > max->value)
	{
		node->target_node = max;
		calc_cost(node, s_a, s_b);
	}
	else
	{
		node->target_node = find_target_node_pos(s_b, node);
		calc_cost(node, s_a, s_b);
	}
}

void	edit_lst_costs(t_list **stack, t_list **other_stack)
{
	t_list	*current;

	current = *stack;
	while (current)
	{
		edit_cost_target(stack, other_stack, current);
		current = current->next;
	}
}

t_list	*select_node(t_list **stack)
{
	t_list	*current;
	t_list	*best_node;

	current = *stack;
	best_node = *stack;
	while (current)
	{
		if (current->cost < best_node->cost)
			best_node = current;
		current = current->next;
	}
	return (best_node);
}

void	move_node(t_list **s_a, t_list **s_b, t_list *node)
{
	t_list	*target;
	int		up_down_a;
	int		up_down_b;

	target = node->target_node;
	while (node->position != 0 || target->position != 0)
	{
		up_down_a = up_or_down(s_a, node);
		up_down_b = up_or_down(s_b, target);
		if (up_down_a == 1 && up_down_b == 1)
			rotate_both(s_a, s_b);
		else if (!up_down_a && !up_down_b)
			reverse_rotate_both(s_a, s_b);
		else if (up_down_a == 1)
			rotate_a(s_a);
		else if (up_down_b == 1)
			rotate_b(s_b);
		else if (!up_down_a)
			reverse_rotate_a(s_a);
		else if (!up_down_b)
			reverse_rotate_b(s_b);
	}
	push_b(s_a, s_b);
}

void	sort_stack_pushb(t_list **s_a, t_list **s_b, int argc)
{
	int		size;
	t_list	*node;

	size = ft_lstsize(s_a);
	while (size > 3)
	{
		node = select_node(s_a);
		move_node(s_a, s_b, node);
		edit_lst_costs(s_a, s_b);
		size--;
	    ft_print_lst(s_a, s_b, argc);
	}
    ft_sort_3(s_a);
}

t_list	*find_higher_node(t_list **stack)
{
	t_list	*current;
	t_list	*higher_node;

	current = *stack;
	higher_node = *stack;
	while (current)
	{
		if (current->value > higher_node->value)
			higher_node = current;
		current = current->next;
	}
	return (higher_node);
}

void	sort_b_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*higher_node;

	higher_node = find_higher_node(stack_b);
	while (higher_node->position != 0)
	{
		if (up_or_down(stack_b, higher_node))
			rotate_b(stack_b);
		else
			reverse_rotate_b(stack_b);
	}
	while (*stack_b)
		push_a(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	if (!args_checker(argc, argv))
	{
		printf("ERROR\n");
		return (-1);
	}
	stack_a = init_stack(argc, argv);
	stack_b = NULL;
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	edit_lst_costs(&stack_a, &stack_b);
	sort_stack_pushb(&stack_a, &stack_b, argc - 1);
	sort_b_push(&stack_a, &stack_b);
	ft_print_lst(&stack_a, &stack_b, argc - 1);
	// ft_push_swap(&stack_a, &stack_b);
	return (0);
}