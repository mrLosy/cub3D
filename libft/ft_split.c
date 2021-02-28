/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:10:53 by haristot          #+#    #+#             */
/*   Updated: 2021/02/21 02:03:26 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	h;

	h = 0;
	i = 0;
	while (s[i] && s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			h++;
		i++;
	}
	return (h);
}

static int		ft_finish(char const *s, char c)
{
	unsigned int	j;

	j = 0;
	while (s[j] != c && s[j] != '\0')
		j++;
	return (j);
}

static char		**free_str(char **ptr, long a)
{
	long	i;

	i = 0;
	while (i < a)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static char		*ft_memory(char *str, char const *s, long len, long a)
{
	long	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (*free_str(&str, a));
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			**ft_split(char const *s, char c)
{
	char	**ptr;
	long	i;
	long	h;
	long	a;

	i = 1;
	h = 0;
	a = 0;
	if (s == NULL)
		return (NULL);
	if (!(ptr = (char **)malloc((ft_words(s, c) + 2) * sizeof(char *))))
		return (free_str(ptr, a));
	while (s[h] != '\0')
	{
		if (s[h] != c)
		{
			i = ft_finish(&s[h], c);
			ptr[a] = ft_memory(ptr[a], &s[h], i, a);
			a++;
		}
		h = h + i;
		i = 1;
	}
	ptr[a] = NULL;
	return (ptr);
}
