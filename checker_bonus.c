/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:39:04 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/12 18:54:19 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	check_op(char *str)
{
	int	flag;

	flag = 0;
	if (!ft_strncmp(str, "sa", 2) || !ft_strncmp(str, "sb", 2)
		|| !ft_strncmp(str, "ss", 2) || !ft_strncmp(str, "pa", 2)
		|| !ft_strncmp(str, "pb", 2) || !ft_strncmp(str, "ra", 2)
		|| !ft_strncmp(str, "rb", 2) || !ft_strncmp(str, "rr", 2)
		|| !ft_strncmp(str, "rra", 3) || !ft_strncmp(str, "rrb", 3)
		|| !ft_strncmp(str, "rrr", 3))
		flag = 1;
    return (flag);
}

void    exec_op(t_list **s_a, t_list **s_b, char *str)
{
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
    if (!ft_strncmp(str, "rra", 3))
        return (reverse_rotate(s_a));
    if (!ft_strncmp(str, "rrb", 3))
        return (reverse_rotate(s_b));
    if (!ft_strncmp(str, "rrr", 3))
        return (reverse_rotate_both(s_a, s_b, 0));
}

void    get_instructions(t_list **s_a, t_list **s_b)
{
	char	*str;
	int		i;

	str = get_next_line(1, 0);
	i = -1;
	while (1)
	{
		if (!check_op(str))
		{
			ft_printf("Error\n");
            return ;
		}
        exec_op(s_a, s_b, str);
        get_next_line(0, 1);
	}
}

int	main(int argc, char **argv)
{
    t_list  *stack_a;
    t_list  *stack_b;
    char    **args;

	argc -= 1;
    args = args_checker(argc, argv);
    if (!args)
    {
		printf("Error\n");
		return (-1);
	}
    stack_a = init_stack(argc, argv);
	stack_b = NULL;
    get_instructions(&stack_a, &stack_b);
}
