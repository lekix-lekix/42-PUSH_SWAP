/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:16:46 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/29 17:22:17 by kipouliq         ###   ########.fr       */
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

int	ft_verify_stack(t_list **stack, char **args)
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
				ft_free_tab(args);
				return (0);
			}
			current = current->next;
		}
		elem_cmp = elem_cmp->next;
	}
	return (1);
}

char	**args_split(char **argv)
{
	char	**args;
	char	*args_str;
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (i == 1)
			args_str = ft_strjoin_space(NULL, argv[i]);
		else
			args_str = ft_strjoin_space(args_str, argv[i]);
		if (!args_str)
			return (NULL);
	}
	args = ft_split(args_str, ' ');
	if (!args)
	{
		free(args_str);
		return (NULL);
	}
	free(args_str);
	return (args);
}

char	**args_checker(char **argv)
{
	char	**args;
	int		args_check;

	args = args_split(argv);
	if (!args)
		return (NULL);
	args_check = args_parsing(args, tab_size(args));
	if (args_check)
		return (args);
	else
		return (ft_free_tab(args));
}
