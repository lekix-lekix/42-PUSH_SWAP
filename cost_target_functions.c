/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_target_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:04:18 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/22 16:09:50 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	calc_cost(t_list **s_a, t_list **s_b)
{
	t_list	*current;
	t_list	*target;
	int		ppdc;

	current = *s_b;
	while (current)
	{
		target = current->target_node;
		if (current->cost < target->cost)
			ppdc = current->cost;
		else
			ppdc = target->cost;
		if (up_or_down(s_b, current) == up_or_down(s_a, target))
			current->cost += target->cost - ppdc;
		else
			current->cost += target->cost;
		current = current->next;
	}
}

void	calc_cost_first_pos(t_list **stack)
{
	t_list	*current;
	int		up_down;

	current = *stack;
	while (current)
	{
		current->cost = 0;
		up_down = up_or_down(stack, current);
		if (up_down == 1 || up_down == 0)
			current->cost += current->position;
		else
			current->cost += ft_listsize(stack) - current->position;
		current = current->next;
	}
}

void	edit_list_costs(t_list **s_a, t_list **s_b)
{
	calc_cost_first_pos(s_a);
	calc_cost_first_pos(s_b);
	set_targets(s_a, s_b);
	calc_cost(s_a, s_b);
}

t_list	*find_target_node_a(t_list **stack, t_list *node)
{
	t_list	*current;
	t_list	*closest;
	int		closest_distance;

	current = *stack;
	closest = NULL;
	closest_distance = calc_distance(ft_min_max(stack, 1)->value,
			ft_min_max(stack, 0)->value);
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

void	set_targets(t_list **s_a, t_list **s_b)
{
	t_list	*min;
	t_list	*max;
	t_list	*current;

	min = ft_min_max(s_a, 0);
	max = ft_min_max(s_a, 1);
	current = *s_b;
	while (current)
	{
		if (current->value < min->value || current->value > max->value)
			current->target_node = min;
		else
			current->target_node = find_target_node_a(s_a, current);
		current = current->next;
	}
}
