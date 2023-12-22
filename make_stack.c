/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:28:13 by kipouliq          #+#    #+#             */
/*   Updated: 2023/12/19 19:08:22 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

void    ft_print_lst(t_list **lst)
{
    t_list  *current;

    current = *lst;
    while (current)
    {
        printf("current = %d\n", current->value);
        current = current->next;
    }
}

t_list  *ft_lstnew(int nb)
{
    t_list  *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->value = nb;
    new_node->next = NULL;    
    return (new_node);
}

void    ft_lstadd_back(t_list **stack, t_list *new_node)
{
    t_list *current;
    
    current = *stack;
    while (current->next)
        current = current->next;
    current->next = new_node;
}

t_list	*init_stack_a(int argc, char **args)
{
	int		i;
	int		nb;
	t_list	*elem;
	t_list	*stack;

	i = 0;
    stack = NULL;
	while (--argc > 0)
	{
		nb = ft_atoi(args[argc]);
		elem = ft_lstnew(nb);
		if (!elem)
			return (NULL); // a changer, need free function
        if (!stack)
        {
            stack = elem;
            continue;
        }
        ft_lstadd_back(&stack, elem);
	}
	return (stack);
}

void    swap(t_list **stack)
{
    t_list *tmp;

    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
}

void    rotate(t_list **stack)
{
    t_list *tmp;
    t_list *current;

    tmp = *stack;
    *stack = (*stack)->next;
    current = *stack;
    while (current->next)
        current = current->next;
    current->next = tmp;
    tmp->next = NULL;
}

void    reverse_rotate(t_list **stack)
{
    t_list *current;
    t_list *prev;
    // t_list *tmp;

    current = *stack;
    while (current->next)
    {
        prev = current;                 // not good
        current = current->next;
    }
    current->next = *stack;
    prev->next = NULL;
}

int	main(int argc, char **argv)
{
	t_list *stack_a;

	stack_a = init_stack_a(argc, argv);
    ft_print_lst(&stack_a);
    reverse_rotate(&stack_a);
    printf("----\n");
    ft_print_lst(&stack_a);
    // ft_lstclear(stack_a);
}