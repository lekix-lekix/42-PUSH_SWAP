/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:56:13 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/28 21:44:39 by lekix            ###   ########.fr       */
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

char	*ft_strjoin_space(char const *s1, char const *s2)
{
	size_t		s1_size;
	size_t		s2_size;
	char		*final_str;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	final_str = malloc(sizeof(char) * (s1_size + s2_size) + 2);
	if (!final_str)
		return (NULL);
	ft_strlcpy(final_str, s1, s1_size + 1);
    final_str[s1_size] = ' ';
	ft_strlcpy(final_str + s1_size + 1, s2, s2_size + 1);
	return (final_str);
}