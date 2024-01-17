/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:28:19 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/17 18:00:15 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_exit_msg(int check_op, int sorted)
{
	if (check_op == -1)
		return (0);
	else if (sorted)
		return (ft_printf("OK\n"));
	else
		return (ft_printf("KO\n"));
}
