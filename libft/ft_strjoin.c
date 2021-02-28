/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 02:34:09 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 09:01:50 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	j;
	size_t	h;

	h = 0;
	j = 0;
	if (!(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	while (s1[h] != '\0')
		str[j++] = s1[h++];
	h = 0;
	while (s2[h] != '\0')
		str[j++] = s2[h++];
	str[j] = '\0';
	return (str);
}
