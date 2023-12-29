/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:12:58 by kipouliq          #+#    #+#             */
/*   Updated: 2023/12/29 19:00:32 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	calc_distance(int nb1, int nb2)
{
	int	diff;

	diff = 0;
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
	int		current_distance;

	current = *stack;
	closest_distance = calc_distance(current->value, node->value);
	while (current)
	{
		current_distance = calc_distance(current->value, node->value);
		if (current_distance < closest_distance
			|| (current_distance == closest_distance
				&& node->value < current->value))
		{
			closest_distance = current_distance;
			closest = current;
		}
		current = current->next;
	}
	return (closest);
}

void    calc_cost(t_list *node, t_list *min_max, t_list *closest_node)
{
    if (closest_node)
    {
        if (closest_node->position >= (min_max->position / 2))
            node->cost = node->position + (min_max->position - closest_node->position) + 1;
        else
            node->cost = node->position + closest_node->position + 1;
    }
    else
    {
        // if (node->position >= (min_max->position / 2))
        //     node->cost = node->position + (min_max->position - node->position);
        // else
        node->cost = node->position + min_max->position + 1;
    }
}

void	edit_node_cost(t_list **stack, t_list *node)
{
	t_list	*closest_node;
	t_list	*min;
	t_list	*max;

	min = ft_min_max(stack, 0);
	max = ft_min_max(stack, 1);
	if (node->value < min->value)
        calc_cost(node, min, NULL);
	else if (node->value > max->value)
        calc_cost(node, max, NULL);
	else
	{
		closest_node = find_target_node_pos(stack, node);
        calc_cost(node, max, closest_node);
	}
	// if (!(node->cost))
		// node->cost = 1;
}

void    edit_lst_costs(t_list **stack_a, t_list **stack_b)
{
    t_list *current;

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
	t_list *current;

	if (!args_checker(argc, argv))
	{
		printf("ERROR\n");
		return (-1);
	}
	stack_a = init_stack(argc, argv);
	stack_b = NULL;
	current = stack_a;
    ft_print_lst(&stack_a, &stack_b, argc - 1);
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