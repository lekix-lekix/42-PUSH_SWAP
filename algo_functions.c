/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:12:58 by kipouliq          #+#    #+#             */
/*   Updated: 2023/12/30 17:24:32 by lekix            ###   ########.fr       */
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

void	calc_cost(t_list *node, t_list *closest, t_list **s_a, t_list **s_b)
{
	int	size;
	int	cost;

	cost = 0;
	size_a = ft_lstsize(s_a);
	size_b = ft_lstsize(s_b);
    if (size_a % 2 == 0 && node->position < size_a / 2)
        
	// if (size % 2 == 0 && closest->position < size / 2)
	// node->cost = node->position + closest->position;
	// else if (size % 2 != 0 && closest->position <= size / 2)
	// node->cost = node->position + closest->position;
	// else
	// node->cost = node->position + (size - closest->position);
}

void	edit_node_cost(t_list **stack, t_list *node)
{
	t_list	*closest_node;
	t_list	*min;
	t_list	*max;

	min = ft_min_max(stack, 0);
	max = ft_min_max(stack, 1);
	if (node->value < min->value)
	{
		closest_node = min;
		calc_cost(node, min, stack);
	}
	else if (node->value > max->value)
	{
		closest_node = max;
		calc_cost(node, max, stack);
	}
	else
	{
		closest_node = find_target_node_pos(stack, node);
		printf("node = %d, target = %d\n", node->value, closest_node->value);
		calc_cost(node, closest_node, stack);
	}
}

void	edit_lst_costs(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	current = *stack_a;
	while (current)
	{
		edit_node_cost(stack_b, current);
		current = current->next;
	}
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
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	edit_lst_costs(&stack_a, &stack_b);
	ft_print_lst(&stack_a, &stack_b, argc - 1);
	// ft_push_swap(&stack_a, &stack_b);
	return (0);
}