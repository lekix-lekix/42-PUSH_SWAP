/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:12:58 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/09 18:45:32 by lekix            ###   ########.fr       */
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

// void	calc_cost(t_list *node, t_list **s_a, t_list **s_b)
// {
// 	int		size_a;
// 	int		size_b;
// 	int		cost_node;
// 	int		cost_target;
// 	t_list	*target;

// 	size_a = ft_lstsize(s_a);
// 	size_b = ft_lstsize(s_b);
// 	cost_node = 0;
// 	cost_target = 0;
// 	target = node->target_node;
// 	if (up_or_down(s_a, node) == 1 || !up_or_down(s_a, node))
// 		cost_node += node->position;
// 	else
// 		node->cost += size_a - node->position;
// 	if (up_or_down(s_b, target) == 1 || !up_or_down(s_b, target))
// 		node->cost += target->position;
// 	else
// 		node->cost += size_b - target->position;
// 	if (up_or_down(s_a, node) == up_or_down(s_b, target))
// 	{
// 		if (node->cost)
// 	}
// }

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
			current->cost += ft_lstsize(stack) - current->position;
		current = current->next;
	}
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

// void	edit_lst_costs(t_list **s_a, t_list **s_b, char a_b)
// {
// 	t_list	*current;

// 	if (a_b == 'b')
// 	{
// 		current = *s_a;
// 		while (current)
// 		{
// 			edit_cost_target_pushb(s_a, s_b, current);
// 			current = current->next;
// 		}
// 	}
// 	else
// 	{
// 		current = *s_b;
// 		while (current)
// 		{
// 			set_targets(s_a, s_b, current);
// 			current = current->next;
// 		}
// 	}
// }

void	edit_lst_costs(t_list **s_a, t_list **s_b)
{
	calc_cost_first_pos(s_a);
	calc_cost_first_pos(s_b);
	set_targets(s_a, s_b);
	calc_cost(s_a, s_b);
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

void	push_to_stack(t_list **s_a, t_list **s_b, char a_b)
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
		up_down_a = up_or_down(s_a, node);
		// printf("ud a = %d\n", up_down_a);
		up_down_b = up_or_down(s_b, target);
		// printf("ud b = %d\n", up_down_b);
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

void	sort_stack_pushb(t_list **s_a, t_list **s_b /* int argc */)
{
	int		size;
	t_list	*node;

	size = ft_lstsize(s_a);
	while (size > 2)
	{
		node = select_node(s_a);
		move_node_b(s_a, s_b, node, 'b'); // argc remove
		edit_lst_costs(s_a, s_b);
		size--;
		// ft_print_lst(s_a, s_b, argc);
		// printf("=====\n");
	}
	ft_sort_3(s_a);
}

// void	sort_stack_pusha(t_list **s_a, t_list **s_b /* int argc */)
// {
// 	t_list	*node;

// 	while (*s_b)
// 	{
// 		node = select_node(s_b);
// 		move_node_a(s_a, s_b, node, 'a');
// 		edit_lst_costs(s_a, s_b, 'a');
// 		// ft_print_lst(s_a, s_b, argc);
// 		// printf("=====\n");
// 	}
// }

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

int	is_chunk_done(t_list **stack, int chunk_nb)
{
	t_list	*current;

	current = *stack;
	while (current)
	{
		if (current->chunk_nb == chunk_nb)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_stack_pusha(t_list **s_a, t_list **s_b, int nb, int argc)
{
	t_list	*node;

	(void)argc;
	while (*s_b)
	{
		node = select_best_node(s_b, nb);
		move_node_a(s_a, s_b, node, 'a');
		edit_lst_costs(s_a, s_b);
		if (is_chunk_done(s_b, nb))
			nb--;
		// ft_print_lst(s_a, s_b, argc);
		// printf("=====\n");
	}
}

// void    sort_stack_pusha(t_list **s_a, t_list **s_b, int nb)
// {
//     t_list *node;
//     int     i;

//     i = nb;
//     while (*s_b && i != 0)
//     {
//         node = select_chunk_node(s_b, nb);
//         move_node_a(s_a, s_b, node, 'a');
//         edit_lst_costs(s_a, s_b, 'a');
//         if (is_chunk_done(s_a, i))
//             i--;
//     }
// }

void	final_order(t_list **stack)
{
	t_list	*lower_node;
	int		size;

	size = ft_lstsize(stack);
	lower_node = ft_min_max(stack, 0);
	while (lower_node->position != 0)
	{
		if (lower_node->position <= size / 2)
			rotate_a(stack);
		else
			reverse_rotate_a(stack);
	}
}

void	assign_chunk_nb(t_list **s_a, int nb)
{
	t_list	*current;
	int		chunk_size;
	int		i;
	int		j;

	current = *s_a;
	chunk_size = ft_lstsize(s_a) / nb;
	i = 1;
	j = 0;
	while (i <= nb)
	{
		if (current->index < chunk_size * i && current->chunk_nb == -1)
		{
			current->chunk_nb = i;
			j++;
		}
		if (j == chunk_size)
		{
			j = 0;
			i++;
		}
		current = current->next;
		if (!current)
			current = *s_a;
	}
}

t_list	*find_closest_index(t_list **stack, t_list *node)
{
	t_list	*current;
	t_list	*closest;
	int		distance;

	current = *stack;
	closest = ft_min_max(stack, 1);
	distance = calc_distance(node->value, ft_min_max(stack, 1)->value);
	while (current)
	{
		if (calc_distance(current->value, node->value) < distance
			&& node->value < current->value)
		{
			distance = calc_distance(current->value, node->value);
			closest = current;
		}
		current = current->next;
	}
	return (closest);
}

void	assign_index(t_list **stack)
{
	t_list	*min;
	t_list	*closest;
	int		i;
	int		size;

	min = ft_min_max(stack, 0);
	min->index = 0;
	size = ft_lstsize(stack);
	i = 1;
	while (i < size)
	{
		closest = find_closest_index(stack, min);
		closest->index = i;
		min = closest;
		i++;
	}
}

void	push_node_b(t_list **s_a, t_list **s_b, t_list *node)
{
	int	node_direction;

	node_direction = up_or_down(s_a, node);
	if (node->position == 0)
		return (push_b(s_a, s_b));
	while (node->position != 0)
	{
		if (node_direction == 1)
			rotate_a(s_a);
		else
			reverse_rotate_a(s_a);
	}
	push_b(s_a, s_b);
}

// void	push_chunks_b(t_list **s_a, t_list **s_b)
// {
// 	middle = ft_lstsize(s_a) / 2;
// 	printf("mid = %d\n", middle);
// 	current = *s_a;
// 	while (current)
// 	{
// 		if (current->index < middle)
// 		{
// 			push_node_b(s_a, s_b, current);
// 			current = *s_a;
// 			continue ;
// 		}
// 		current = current->next;
// 	}
// 	while (ft_lstsize(s_a) != 3)
// 		push_b(s_a, s_b);
// 	ft_sort_3(s_a);
// }

void	push_chunks_b(t_list **s_a, t_list **s_b, int nb)
{
	t_list	*current;
	t_list	*node;
	int		chunk_size;
	int		j;
	int		i;

	i = 1;
	j = 0;
	current = *s_a;
	chunk_size = ft_lstsize(s_a) / nb;
	while (ft_lstsize(s_a) > 3)
	{
		node = select_best_node(s_a, i);
		// printf("node = %d target = %d\n", node->value,
		// node->target_node->value);
		// printf("node %d chunk %d\n", node->value, node->chunk_nb);
		push_node_b(s_a, s_b, node);
		j++;
		if (j == chunk_size)
		{
			j = 0;
			i++;
		}
		current = current->next;
		if (!current)
			current = *s_a;
		calc_cost_first_pos(s_a);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;

	// int		middle;
	args = args_checker(argc, argv);
	if (!args)
	{
		printf("ERROR\n");
		return (-1);
	}
	stack_a = init_stack(argc, argv);
	stack_b = NULL;
	assign_index(&stack_a);
	assign_chunk_nb(&stack_a, 11);
	calc_cost_first_pos(&stack_a);
	push_chunks_b(&stack_a, &stack_b, 11);
	ft_sort_3(&stack_a);
	edit_lst_costs(&stack_a, &stack_b);
	// ft_print_lst(&stack_a, &stack_b, argc - 1);
	sort_stack_pusha(&stack_a, &stack_b, 11, argc - 1);
	// ft_print_lst(&stack_a, &stack_b, argc - 1);
	// sort_stack_pushb(&stack_a, &stack_b /* argc - 1 */);
	// middle = ft_lstsize(&stack_a) / 2;
	// push_chunks_b(&stack_a, &stack_b);
	final_order(&stack_a);
	// edit_lst_costs(&stack_a, &stack_b, 'b');
	// ft_push_swap(&stack_a, &stack_b);
	return (0);
}
