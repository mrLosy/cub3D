/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:06:56 by haristot          #+#    #+#             */
/*   Updated: 2020/11/27 12:41:42 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	unsigned int	h;

	h = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		h++;
	while (n != 0)
	{
		n = n / 10;
		h++;
	}
	return (h);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	i;

	if (n == -2147483648)
		return ((str = ft_strdup("-2147483648")) == 0 ? 0 : str);
	i = ft_len(n);
	if (!(str = (char *)ft_calloc((i + 1), sizeof(char))))
		return (0);
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (n != 0)
	{
		str[--i] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
