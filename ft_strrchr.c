/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:29:54 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/09 12:48:54 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		size;
	char	a;

	size = ft_strlen(s);
	i = size;
	a = (char)c;
	while (s[i] != a && i >= 0)
	{
		i--;
	}
	if (s[i] == '\0')
	{
		if (a == '\0')
		{
			return ((char *)&s[i]);
		}
		return (NULL);
	}
	return ((char *)s + i);
}
