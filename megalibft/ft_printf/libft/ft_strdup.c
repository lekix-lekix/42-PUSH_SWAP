/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:57:03 by kipouliq          #+#    #+#             */
/*   Updated: 2023/11/14 18:23:25 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*final_str;
	int		s_len;

	s_len = ft_strlen(s);
	final_str = malloc(sizeof(char) * (s_len + 1));
	if (!final_str)
		return (NULL);
	ft_strlcpy(final_str, s, s_len + 1);
	return (final_str);
}
