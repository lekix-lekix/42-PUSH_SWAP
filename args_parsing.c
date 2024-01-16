/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:16:46 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/16 17:09:30 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	arg_check(char *str)
{
	int	arg_len;

	arg_len = ft_strlen(str);
	if ((arg_len == 1 && !ft_isdigit(str[0])) || arg_len > 10)
		return (0);
	if (arg_len != 1 && !str_digits_check(str + 1))
		return (0);
	if (arg_len == 10 && !ft_check_overflow(str))
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

char	**args_checker(int *argc, char **args, int *malloc_args)
{
	int	malloc_flag;

	malloc_flag = 0;
	if (*argc == 2)
	{
		args = ft_split(args[1], ' ');
		if (!args)
			return (NULL);
		malloc_flag = 1;
	}
	if (!malloc_flag && args_parsing(args + 1, tab_size(args) - 1))
		return (args + 1);
	else if (malloc_flag && args_parsing(args, tab_size(args)))
	{
		*argc = tab_size(args) + 1;
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
