/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:56:03 by haristot          #+#    #+#             */
/*   Updated: 2021/02/10 11:34:47 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_n(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 2))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '+';
	str[i + 1] = '\0';
	return (str);
}
