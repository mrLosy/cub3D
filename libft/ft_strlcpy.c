/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:49:34 by haristot          #+#    #+#             */
/*   Updated: 2020/11/20 03:12:32 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	f;

	i = 0;
	f = 0;
	if (!dst || !src)
		return (0);
	while (src[i] != '\0')
		i++;
	if (dstsize)
	{
		dstsize--;
		while (src[f] != '\0' && dstsize--)
		{
			dst[f] = src[f];
			f++;
		}
		dst[f] = '\0';
	}
	return (i);
}
