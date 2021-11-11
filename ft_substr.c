/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:59:33 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/11 11:37:33 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	l;

	if (!s)
		return (0);
	substr = (char *)malloc(len + 1);
	i = 0;
	l = (int)len;
	if (substr == NULL)
	{
		return (NULL);
	}
	if (start >= ft_strlen(s))
		return (substr);
	while (i < l)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
