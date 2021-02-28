/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:26:44 by haristot          #+#    #+#             */
/*   Updated: 2020/11/20 03:18:33 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*str;

	ptr = (unsigned char *)s1;
	str = (unsigned char *)s2;
	if (!n)
		return (0);
	while (n--)
	{
		if (*ptr != *str)
			return (*ptr - *str);
		ptr++;
		str++;
	}
	return (0);
}
