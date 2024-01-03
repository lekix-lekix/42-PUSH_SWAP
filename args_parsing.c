/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:16:46 by kipouliq          #+#    #+#             */
/*   Updated: 2023/12/30 13:59:23 by lekix            ###   ########.fr       */
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

int	solo_arg_check(char *str)
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

int	args_checker(int argc, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		if (!solo_arg_check(args[i]))
			return (0);
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(args[i], args[j]))
				return (0);
			j++;
		}
	}
	return (1);
}
