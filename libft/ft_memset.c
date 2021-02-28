/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:35:41 by haristot          #+#    #+#             */
/*   Updated: 2020/11/20 03:16:17 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;
	unsigned char str;

	ptr = (unsigned char *)b;
	str = (unsigned char)c;
	while (len--)
		*ptr++ = str;
	return (b);
}
