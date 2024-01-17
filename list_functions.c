/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:39:59 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/17 15:08:04 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_list	*ft_listnew(int nb, int pos)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = nb;
	new_node->position = pos;
	new_node->index = -1;
	new_node->chunk_nb = -1;
	new_node->target_node = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	ft_listadd_back(t_list **stack, t_list *new_node)
{
	t_list	*current;

	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

t_list	*init_stack(int argc, char **args)
{
	int		i;
	int		nb;
	t_list	*elem;
	t_list	*stack;

	i = -1;
	stack = NULL;
	while (++i < argc)
	{
		nb = ft_atoi(args[i]);
		elem = ft_listnew(nb, i - 1);
		if (!elem)
			return (ft_free_lst(&stack));
		if (!stack)
		{
			stack = elem;
			continue ;
		}
		ft_listadd_back(&stack, elem);
	}
	return (stack);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*next_node;

	current = *stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}
