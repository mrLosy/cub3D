/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:39:54 by haristot          #+#    #+#             */
/*   Updated: 2020/11/20 03:27:52 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr;
	char	*str;
	size_t	i;

	ptr = dst;
	str = (char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (ptr < str)
	{
		while (i++ < len)
			*ptr++ = *str++;
	}
	else
	{
		while (len > 0)
		{
			*(ptr + (len - 1)) = *(str + (len - 1));
			len--;
		}
	}
	return (dst);
}
