/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:07:50 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/22 16:44:54 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (0);
}

void	final_order(t_list **stack)
{
	t_list	*lower_node;
	int		size;

	size = ft_listsize(stack);
	lower_node = ft_min_max(stack, 0);
	while (lower_node->position != 0)
	{
		if (lower_node->position <= size / 2)
			rotate_a(stack);
		else
			reverse_rotate_a(stack);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	str_digits_check(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == '-' || str[i] == '+') && i == 0)
			continue ;
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	ft_check_overflow(char *str)
{
	int		nb;
	char	*test_str;

	nb = ft_atoi(str);
	test_str = ft_itoa(nb);
	if (!test_str)
		return (0);
	if (!ft_strcmp(str, test_str))
	{
		free(test_str);
		return (0);
	}
	free(test_str);
	return (1);
}
