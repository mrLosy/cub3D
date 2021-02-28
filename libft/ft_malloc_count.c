/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:24:25 by haristot          #+#    #+#             */
/*   Updated: 2021/02/09 12:24:43 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_malloc_count(unsigned long int a)
{
	unsigned int	count;

	count = 0;
	if (a == 0)
		return (1);
	while (a != 0)
	{
		count++;
		a /= 16;
	}
	return (count);
}
