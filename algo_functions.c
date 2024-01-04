/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:12:58 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/04 16:55:54 by kipouliq         ###   ########.fr       */
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

t_list	*find_target_node_b(t_list **stack, t_list *node)
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

t_list	*find_target_node_a(t_list **stack, t_list *node)
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
		if (node->value < current->value && calc_distance(current->value,
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
		return (0);
	if ((size % 2 == 0 && node->position < size / 2) || (size % 2 != 0
			&& node->position <= size / 2))
		return (1);
	else
		return (-1);
}

void	calc_cost(t_list *node, t_list **s_a, t_list **s_b)
{
	int		size_a;
	int		size_b;
	t_list	*target;

	size_a = ft_lstsize(s_a);
	size_b = ft_lstsize(s_b);
	target = node->target_node;
	if (up_or_down(s_a, node) == 1 || !up_or_down(s_a, node))
		node->cost += node->position;
	else
		node->cost += size_a - node->position;
	if (up_or_down(s_b, target) == 1 || !up_or_down(s_b, target))
		node->cost += target->position;
	else
		node->cost += size_b - target->position;
}

void	edit_cost_target_pushb(t_list **s_a, t_list **s_b, t_list *node)
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
		node->target_node = find_target_node_b(s_b, node);
		calc_cost(node, s_a, s_b);
	}
}

void    edit_cost_target_pusha(t_list **s_a, t_list **s_b, t_list *node)
{
    t_list *min;
    t_list *max;

    min = ft_min_max(s_a, 0);
    max = ft_min_max(s_a, 1);
    node->cost = 0;
    if (node->value < min->value || node->value > max->value)
    {
        node->target_node = min;
        calc_cost(node, s_b, s_a);
    }
    else
    {
        // printf("Coucou\n");
        node->target_node = find_target_node_a(s_a, node);
        calc_cost(node, s_b, s_a);
    }
    // printf("node = %d target = %d pos = %d\n", node->value, node->target_node->value, node->position);
}

void	edit_lst_costs(t_list **s_a, t_list **s_b, char a_b)
{
	t_list	*current;

    if (a_b == 'b')
    {
	    current = *s_a;
        while (current)
        {
            edit_cost_target_pushb(s_a, s_b, current);
    		current = current->next;
        }
    }
    else
	{
        current = *s_b;
        while (current)
        {
            edit_cost_target_pusha(s_a, s_b, current);
            current = current->next;
        }
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

void    push_to_stack(t_list **s_a, t_list **s_b, char a_b)
{
    if (a_b == 'b')
        push_b(s_a, s_b);
    else
        push_a(s_a, s_b);
}

void	move_node_b(t_list **s_a, t_list **s_b, t_list *node, char a_b)
{
	t_list	*target;
	int		up_down_a;
	int		up_down_b;

	target = node->target_node;
	while (node->position != 0 || target->position != 0)
	{
		up_down_a = up_or_down(s_b, node);
		up_down_b = up_or_down(s_a, target);
		if (up_down_a == 1 && up_down_b == 1)
			rotate_both(s_a, s_b);
		else if (up_down_a == -1 && up_down_b == -1)
			reverse_rotate_both(s_a, s_b);
		else if (up_down_a == 1)
			rotate_a(s_a);
		else if (up_down_b == 1)
			rotate_b(s_b);
		else if (up_down_a == -1)
			reverse_rotate_a(s_a);
		else if (up_down_b == -1)
			reverse_rotate_b(s_b);
	}
    push_to_stack(s_a, s_b, a_b);
}

void	move_node_a(t_list **s_a, t_list **s_b, t_list *node, char a_b)
{
    t_list	*target;
	int		up_down_a;
	int		up_down_b;

	target = node->target_node;
	while (node->position != 0 || target->position != 0)
	{
		up_down_a = up_or_down(s_a, target);
		up_down_b = up_or_down(s_b, node);
		if (up_down_a == 1 && up_down_b == 1)
			rotate_both(s_a, s_b);
		else if (up_down_a == -1 && up_down_b == -1)
			reverse_rotate_both(s_a, s_b);
		else if (up_down_a == 1)
			rotate_a(s_a);
		else if (up_down_b == 1)
			rotate_b(s_b);
		else if (up_down_a == -1)
			reverse_rotate_a(s_a);
		else if (up_down_b == -1)
			reverse_rotate_b(s_b);
	}
    push_to_stack(s_a, s_b, a_b);
}

void	sort_stack_pushb(t_list **s_a, t_list **s_b)
{
	int		size;
	t_list	*node;

	size = ft_lstsize(s_a);
	while (size > 3)
	{
		node = select_node(s_a);
		move_node_b(s_a, s_b, node, 'b');  // argc remove
		edit_lst_costs(s_a, s_b, 'b');
		size--;
	    // ft_print_lst(s_a, s_b, argc);
	}
    ft_sort_3(s_a);
}

// t_list *select_node_pusha(t_list **s_a, t_list **s_b, t_list *node)
// {
    
// }

void    sort_stack_pusha(t_list **s_a, t_list **s_b)
{
    t_list *node;

    while (*s_b)
    {
        node = select_node(s_b);
        // printf("node %d target = %d \n", node->value, node->target_node->value);
        move_node_a(s_a, s_b, node, 'a');
        edit_lst_costs(s_a, s_b, 'a');
	    // ft_print_lst(s_a, s_b, argc);
        // printf("=====\n");`
    }
}

void    final_order(t_list **stack)
{
    t_list *lower_node;
    t_list *current;
    int     size;
    int     up;

    size = ft_lstsize(stack);
    current = *stack;
    lower_node = *stack;
    while (current)
    {
        if (lower_node->value > current->value)
            lower_node = current;
        current = current->next;
    }
    up = up_or_down(stack, lower_node);
    while (lower_node->position != 0)
    {
        if (up)
            rotate_a(stack);
        else
            reverse_rotate_a(stack);
    }
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
    char    **args;

	if (!args_checker(argc, argv))
	{
		printf("ERROR\n");
		return (-1);
	}
	stack_a = init_stack(argc, argv);
	stack_b = NULL;
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	// ft_print_lst(&stack_a, &stack_b, argc - 1);
	edit_lst_costs(&stack_a, &stack_b, 'b');
	sort_stack_pushb(&stack_a, &stack_b);
	edit_lst_costs(&stack_a, &stack_b, 'a');
    sort_stack_pusha(&stack_a, &stack_b);
    final_order(&stack_a);
	// ft_print_lst(&stack_a, &stack_b, argc - 1);
	// ft_push_swap(&stack_a, &stack_b);
	return (0);
}
