/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:13:43 by haristot          #+#    #+#             */
/*   Updated: 2021/02/25 17:07:20 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;

	j = 0;
	if (!haystack)
		return (NULL);
	if (!needle)
		return ((char *)haystack);
	j = ft_strlen(needle);
	while (haystack && len-- >= j)
	{
		if (ft_strncmp(haystack, needle, j) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
