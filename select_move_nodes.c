/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_move_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:51:11 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/16 17:17:01 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_list	*select_best_node(t_list **stack, int nb)
{
	t_list	*current;
	t_list	*best_node;

	current = *stack;
	best_node = *stack;
	while (current)
	{
		if (current->chunk_nb == nb)
			best_node = current;
		current = current->next;
	}
	current = *stack;
	while (current)
	{
		if (current->chunk_nb == nb && current->cost < best_node->cost)
			best_node = current;
		current = current->next;
	}
	return (best_node);
}

void	move_node_a(t_list **s_a, t_list **s_b, t_list *node)
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
			rotate_both(s_a, s_b, 1);
		else if (up_down_a == -1 && up_down_b == -1)
			reverse_rotate_both(s_a, s_b, 1);
		else if (up_down_a == 1)
			rotate_a(s_a);
		else if (up_down_b == 1)
			rotate_b(s_b);
		else if (up_down_a == -1)
			reverse_rotate_a(s_a);
		else if (up_down_b == -1)
			reverse_rotate_b(s_b);
	}
	push_a(s_a, s_b, 1);
}

void	push_node_b(t_list **s_a, t_list **s_b, t_list *node)
{
	int	node_direction;

	node_direction = up_or_down(s_a, node);
	if (node->position == 0)
		return (push_b(s_a, s_b, 1));
	while (node->position != 0)
	{
		if (node_direction == 1)
			rotate_a(s_a);
		else
			reverse_rotate_a(s_a);
	}
	push_b(s_a, s_b, 1);
}
