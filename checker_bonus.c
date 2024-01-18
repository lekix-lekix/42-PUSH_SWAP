/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:39:04 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/18 12:42:01 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	check_op(char *str)
{
	if (ft_strlen(str) != 3 && ft_strlen(str) != 4)
		return (0);
	if (!ft_strncmp(str, "rra\n", 4) || !ft_strncmp(str, "rrb\n", 4)
		|| !ft_strncmp(str, "rrr\n", 4) || !ft_strncmp(str, "sa\n", 3)
		|| !ft_strncmp(str, "sb\n", 3) || !ft_strncmp(str, "ss\n", 3)
		|| !ft_strncmp(str, "pa\n", 3) || !ft_strncmp(str, "pb\n", 3)
		|| !ft_strncmp(str, "ra\n", 3) || !ft_strncmp(str, "rb\n", 3)
		|| !ft_strncmp(str, "rr\n", 3))
		return (1);
	return (0);
}

void	exec_op(t_list **s_a, t_list **s_b, char *str)
{
	if (!ft_strncmp(str, "rra", 3))
		return (reverse_rotate(s_a));
	if (!ft_strncmp(str, "rrb", 3))
		return (reverse_rotate(s_b));
	if (!ft_strncmp(str, "rrr", 3))
		return (reverse_rotate_both(s_a, s_b, 0));
	if (!ft_strncmp(str, "sa", 2))
		return (swap(s_a));
	if (!ft_strncmp(str, "sb", 2))
		return (swap(s_b));
	if (!ft_strncmp(str, "ss", 2))
		return (swap_both(s_a, s_b, 0));
	if (!ft_strncmp(str, "pa", 2))
		return (push_a(s_a, s_b, 0));
	if (!ft_strncmp(str, "pb", 2))
		return (push_b(s_a, s_b, 0));
	if (!ft_strncmp(str, "ra", 2))
		return (rotate(s_a));
	if (!ft_strncmp(str, "rb", 2))
		return (rotate(s_b));
	if (!ft_strncmp(str, "rr", 2))
		return (rotate_both(s_a, s_b, 0));
}

int	get_instructions(t_list **s_a, t_list **s_b)
{
	char	*str;

	str = get_next_line(0, 0);
	while (str)
	{
		if (!check_op(str))
		{
			get_next_line(0, 1);
			ft_print_error();
			free(str);
			return (-1);
		}
		exec_op(s_a, s_b, str);
		free(str);
		str = get_next_line(0, 0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		check_op;
	int		sorted;
	int		malloc_args;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	malloc_args = 0;
	argv = args_checker(&argc, argv, &malloc_args);
	if (!argv)
		return (ft_print_error());
	stack_a = init_stack(argc, argv);
	if (!stack_a)
		return (ft_print_error());
	if (malloc_args)
		ft_free_tab(argv);
	stack_b = NULL;
	check_op = get_instructions(&stack_a, &stack_b);
	sorted = ft_full_verify_sort(&stack_a, &stack_b);
	ft_free_lst(&stack_a);
	ft_free_lst(&stack_b);
	return (ft_exit_msg(check_op, sorted));
}
