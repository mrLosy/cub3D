/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ser_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:48:09 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 04:36:13 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_sprites(t_all *all)
{
	int		i;
	int		h;
	int		k;

	h = 0;
	k = 0;
	while (all->map.map[h])
	{
		i = 0;
		while (all->map.map[h][i])
		{
			if (all->map.map[h][i] == '2')
			{
				all->s[k].x = h + 0.5;
				all->s[k].y = i + 0.5;
				k++;
			}
			i++;
		}
		h++;
	}
}

void		ft_search_sprites(t_all *all)
{
	int		i;
	int		h;

	h = 1;
	all->map.num = 0;
	while (all->map.map[h])
	{
		i = 1;
		while (all->map.map[h][i])
		{
			if (all->map.map[h][i] == '2')
				all->map.num++;
			i++;
		}
		h++;
	}
	if (all->map.num >= 0)
	{
		if (!(all->s = ft_calloc(all->map.num + 1, sizeof(t_sprite))))
			ft_error("Error\n in calloc\n( ・・)つ―{}@{}@{}-\n");
		ft_sprites(all);
	}
}
