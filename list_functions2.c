/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:43:24 by kipouliq          #+#    #+#             */
/*   Updated: 2023/12/27 13:45:16 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_lstsize(t_list **lst)
{
	int	    size;
    t_list  *current;

	if (!*lst)
		return (0);
	size = 0;
    current = *lst;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}