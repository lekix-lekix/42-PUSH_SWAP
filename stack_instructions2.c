/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:29:30 by kipouliq          #+#    #+#             */
/*   Updated: 2023/12/22 14:48:39 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void    swap_both(t_list **s_a, t_list **s_b)
{
    swap(s_a);
    swap(s_b);
    ft_printf("ss\n");
}

void    reverse_both(t_list **s_a, t_list **s_b)
{
    rotate(s_a);
    rotate(s_b);
    ft_printf("rr\n");
}

void    reverse_rotate_a(t_list **stack)
{
    reverse_rotate(stack);
    ft_printf("rra\n");
}

void    reverse_rotate_b(t_list **stack)
{
    reverse_rotate(stack);
    ft_printf("rrb\n");
}