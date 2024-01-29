/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_chunks_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:19:10 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/29 14:20:38 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	assign_index(t_list **stack)
{
	t_list	*min;
	t_list	*closest;
	int		i;
	int		size;

	min = ft_min_max(stack, 0);
	min->index = 0;
	size = ft_listsize(stack);
	i = 1;
	while (i < size)
	{
		closest = find_closest_index(stack, min);
		closest->index = i;
		min = closest;
		i++;
	}
}

t_list	*find_closest_index(t_list **stack, t_list *node)
{
	t_list			*current;
	t_list			*closest;
	long long int	distance;

	current = *stack;
	closest = ft_min_max(stack, 1);
	distance = 4294967295;
	while (current)
	{
		if (node->value < current->value && calc_abs_distance(current->value,
				node->value) < distance)
		{
			distance = calc_abs_distance(current->value, node->value);
			closest = current;
		}
		current = current->next;
	}
	return (closest);
}

void	assign_chunk_nb(t_list **s_a, int nb)
{
	t_list	*current;
	int		chunk_size;
	int		i;
	int		j;

	current = *s_a;
	chunk_size = ft_listsize(s_a) / nb;
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
	chunk_size = ft_listsize(s_a) / nb;
	while (ft_listsize(s_a) > 3)
	{
		node = select_best_node(s_a, i);
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
