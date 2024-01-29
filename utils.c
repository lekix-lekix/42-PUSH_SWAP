/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:54:30 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/29 14:24:51 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

long long int	calc_abs_distance(int nb1, int nb2)
{
	long int	abs_nb1;
	long int	abs_nb2;

	abs_nb1 = abs_value(nb1);
	abs_nb2 = abs_value(nb2);
	if ((nb1 >= 0 && nb2 >= 0) || (nb1 <= 0 && nb2 <= 0))
	{
		if (abs_nb1 > abs_nb2)
			return (abs_value(abs_nb1 - abs_nb2));
		else
			return (abs_value(abs_nb2 - abs_nb1));
	}
	else
		return (abs_nb1 + abs_nb2);
}

int	calc_distance(int nb1, int nb2)
{
	if (nb1 > nb2)
		return (nb1 - nb2);
	else
		return (nb2 - nb1);
}

int	ft_verify_sort(t_list **stack)
{
	t_list	*current;
	t_list	*next;

	current = *stack;
	while (current->next)
	{
		next = current->next;
		if (current->value > next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

t_list	*ft_min_max(t_list **stack, int min_or_max)
{
	t_list	*current;
	t_list	*min_max;

	current = *stack;
	min_max = current;
	while (current)
	{
		if (!min_or_max && current->value < min_max->value)
			min_max = current;
		else if (min_or_max && current->value > min_max->value)
			min_max = current;
		current = current->next;
	}
	return (min_max);
}

int	up_or_down(t_list **stack, t_list *node)
{
	int	size;

	size = ft_listsize(stack);
	if (node->position == 0)
		return (0);
	if ((size % 2 == 0 && node->position < size / 2) || (size % 2 != 0
			&& node->position <= size / 2))
		return (1);
	else
		return (-1);
}
