/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:44:15 by kipouliq          #+#    #+#             */
/*   Updated: 2023/12/22 14:49:24 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void    swap_a(t_list **stack)
{
    swap(stack);
    ft_printf("sa\n");
}

void    swap_b(t_list **stack)
{
    swap(stack);
    ft_printf("sb\n");
}

void    rotate_a(t_list **stack)
{
    rotate(stack);
    ft_printf("ra\n");
}

void    rotate_b(t_list **stack)
{
    rotate(stack);
    ft_printf("rb\n");
}


