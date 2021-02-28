/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:09:27 by haristot          #+#    #+#             */
/*   Updated: 2020/11/26 16:38:33 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dtr;
	unsigned char	*str;
	size_t			i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (0);
	dtr = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (n--)
	{
		*(dtr + i) = *(str + i);
		if (*(str + i) == (unsigned char)c)
			return (dtr + i + 1);
		i++;
	}
	return (NULL);
}
