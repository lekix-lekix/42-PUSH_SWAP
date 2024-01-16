/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:16:46 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/16 15:40:06 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
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

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	char **args;
	int malloc_args;
    
    (void) args;
	malloc_args = 0;
	argv = args_checker(&argc, argv, &malloc_args);
	if (!argv)
	{
		ft_printf("Error\n");
		return (-1);
	}
	int i = -1;
	while (argv[i])
		printf("%s\n", argv[++i]);
	stack_a = init_stack(argc, argv); // needs free
	stack_b = NULL;
    ft_print_list(&stack_a, &stack_b, argc - 1);
	if (malloc_args)
		ft_free_tab(argv);
	if (ft_verify_sort(&stack_a))
	{
		ft_free_lst(&stack_a);
		return (0);
	}
	pick_an_algo(&stack_a, &stack_b, argc - 1);
	ft_free_lst(&stack_a);
	return (0);
}