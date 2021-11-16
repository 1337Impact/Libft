/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:47:55 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/14 13:58:43 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_c(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (c == '\0')
		return (0);
	if (s[0] == c)
		while (s[i] == c && s[i])
			i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] == c && s[i])
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] == c)
		count--;
	return (count + 1);
}

static char	**free_tab(char **array, int x)
{
	while (x >= 0)
	{
		free(array[x]);
		x--;
	}
	free(array);
	return (NULL);
}

static char	**fill(char *s, char c, char **array)
{
	int	i;
	int	x;
	int	a;

	i = 0;
	x = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		a = 0;
		while (s[i + a] != c && s[i + a])
			a++;
		array[x] = (char *)malloc(a + 1);
		if (!array[x])
			return (free_tab(array, x));
		ft_strlcpy(array[x], s + i, a + 1);
		x++;
		i = i + a;
		while (s[i] == c && s[i])
			i++;
	}
	array[x] = (void *)0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (0);
	array = (char **)malloc((count_c((char *)s, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	return (fill((char *)s, c, array));
}
