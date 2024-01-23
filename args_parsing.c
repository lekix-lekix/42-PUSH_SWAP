/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:16:46 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/23 15:21:28 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	arg_check(char *str)
{
	int	arg_len;

	arg_len = ft_strlen(str);
	if (arg_len > 11)
		return (0);
	if (!str_digits_check(str))
		return (0);
	if (arg_len == 1 && !ft_isdigit(str[0]))
		return (0);
	if ((arg_len == 10 || arg_len == 11) && !ft_check_overflow(str))
		return (0);
	return (1);
}

int	tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	args_parsing(char **args, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (!arg_check(args[i]))
			return (0);
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(args[i], args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_verify_stack(t_list **stack, char **args, int *malloc_args)
{
	t_list	*current;
	t_list	*elem_cmp;

	elem_cmp = *stack;
	current = (*stack)->next;
	while (elem_cmp)
	{
		current = elem_cmp->next;
		while (current)
		{
			if (current->value == elem_cmp->value)
			{
				if (*malloc_args == 1)
					ft_free_tab(args);
				return (0);
			}
			current = current->next;
		}
		elem_cmp = elem_cmp->next;
	}
	return (1);
}

char	**args_checker(int *argc, char **args, int *malloc_args)
{
	int	malloc_flag;

	*argc -= 1;
	malloc_flag = 0;
	if (*argc == 1)
	{
		args = ft_split(args[1], ' ');
		if (!args)
			return (NULL);
		malloc_flag = 1;
	}
	if (!malloc_flag && args_parsing(args + 1, tab_size(args + 1)))
		return (args + 1);
	else if (malloc_flag && args_parsing(args, tab_size(args)))
	{
		*argc = tab_size(args);
		*malloc_args = 1;
		return (args);
	}
	else
	{
		if (malloc_flag)
			ft_free_tab(args);
		return (NULL);
	}
}
