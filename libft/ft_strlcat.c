/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:41:42 by haristot          #+#    #+#             */
/*   Updated: 2020/11/20 03:23:02 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	f;
	size_t	j;

	i = 0;
	f = 0;
	i = ft_strlen(dst);
	j = i;
	if (i < dstsize - 1 && dstsize > 0)
	{
		dstsize--;
		while (src[f] != '\0' && i < dstsize)
		{
			dst[i] = src[f];
			f++;
			i++;
		}
		dst[i] = '\0';
	}
	if (j >= dstsize)
		j = dstsize;
	return (j + ft_strlen(src));
}
