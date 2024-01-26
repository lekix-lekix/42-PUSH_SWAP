/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:56:13 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/26 17:51:50 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

int	ft_full_verify_sort(t_list **s_a, t_list **s_b)
{
	t_list	*current;
	t_list	*next;

	if (*s_b)
		return (0);
	current = *s_a;
	while (current->next)
	{
		next = current->next;
		if (current->value > next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

long long int abs_value(long long int a)
{
    if (a < 0)
        return (a *= -1);
    else
        return (a);
}
