/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:43:24 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/17 15:14:25 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_listsize(t_list **lst)
{
	int		size;
	t_list	*current;

	if (!*lst)
		return (0);
	size = 0;
	current = *lst;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}

void	recalculate_position(t_list **stack)
{
	t_list	*current;
	int		i;

	i = 0;
	if (!(*stack))
		return ;
	current = *stack;
	while (current)
	{
		current->position = i;
		i++;
		current = current->next;
	}
}

int	find_node_position(t_list **stack, int nb)
{
	t_list	*current;

	current = *stack;
	while (current)
	{
		if (current->value == nb)
			return (current->position);
		current = current->next;
	}
	return (-1);
}
