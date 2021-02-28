/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:15:45 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 08:47:46 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void			count_sprite_dst(t_all *all)
{
	int			i;

	i = 0;
	while (i < all->map.num)
	{
		all->s[i].dis = \
			((all->map.player_x - all->s[i].x) * \
			(all->map.player_x - all->s[i].x) + \
			(all->map.player_y - all->s[i].y) * \
			(all->map.player_y - all->s[i].y));
		i++;
	}
}

static void			swap_sprites(t_all *all, int j, int i)
{
	float tmp;
	float position;

	tmp = 0;
	position = 0;
	tmp = all->s[j].dis;
	all->s[j].dis = all->s[i].dis;
	all->s[i].dis = tmp;
	position = all->s[i].x;
	all->s[i].x = all->s[j].x;
	all->s[j].x = position;
	position = all->s[i].y;
	all->s[i].y = all->s[j].y;
	all->s[j].y = position;
}

void				sort_sprites(t_all *all)
{
	int			i;
	int			j;

	count_sprite_dst(all);
	j = 0;
	while (j < all->map.num)
	{
		i = 0;
		while (i < all->map.num)
		{
			if (all->s[j].dis > all->s[i].dis)
				swap_sprites(all, i, j);
			i++;
		}
		j++;
	}
}
