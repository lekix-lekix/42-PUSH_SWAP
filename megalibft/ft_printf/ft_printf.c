/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:04:09 by kipouliq          #+#    #+#             */
/*   Updated: 2024/01/29 15:55:54 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_func_ptr(char c, void *curr_arg, int *count)
{
	t_fp_conversion	convert;

	convert = convert_format(c);
	*count += convert(curr_arg);
}

void	ft_str_parse(const char *str, va_list args, int *c_count)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (!t_fp_conversion_check(str[++i]) || !str[i])
			{
				if (!t_fp_conversion_check(str[i]) && !str[i])
				{
					*c_count = -1;
					return ;
				}
				ft_write_count(str[--i], c_count);
				continue ;
			}
			if (str[i] == '%')
				ft_func_ptr(str[i], NULL, c_count);
			else
				ft_func_ptr(str[i], va_arg(args, void *), c_count);
		}
		else
			ft_write_count(str[i], c_count);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(args, format);
	ft_str_parse(format, args, &count);
	va_end(args);
	return (count);
}
