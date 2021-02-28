/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:16:15 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 08:47:28 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void			sprite_dist(t_all *all, double *spritedistance)
{
	int		i;

	i = 0;
	while (i < all->map.num)
	{
		spritedistance[i] = ((all->map.player_x - all->s[i].x) *\
			(all->map.player_x - all->s[i].x) + (all->map.player_y\
			- all->s[i].y) * (all->map.player_y - all->s[i].y));
		i++;
	}
}

static void			calc_sprite(t_all *all, int i)
{
	all->spr.sprite_x = all->s[i].x - all->map.player_x;
	all->spr.sprite_y = all->s[i].y - all->map.player_y;
	all->spr.inv_det = 1.0 / (all->rayc.plane_x * all->rayc.dir_y\
		- all->rayc.dir_x * all->rayc.plane_y);
	all->spr.tran_x = all->spr.inv_det * (all->rayc.dir_y * all->spr.sprite_x\
		- all->rayc.dir_x * all->spr.sprite_y);
	all->spr.tran_y = all->spr.inv_det * (-all->rayc.plane_y *\
		all->spr.sprite_x + all->rayc.plane_x * all->spr.sprite_y);
	all->spr.spr_screen_x = (int)((all->info.x / 2) * (1 + all->spr.tran_x\
		/ all->spr.tran_y));
	all->spr.sprite_height = abs((int)(all->info.y / (all->spr.tran_y)));
	all->spr.draw_start_y = -all->spr.sprite_height / 2 + all->info.y / 2;
	if (all->spr.draw_start_y < 0)
		all->spr.draw_start_y = 0;
	all->spr.draw_end_y = all->spr.sprite_height / 2 + all->info.y / 2;
	if (all->spr.draw_end_y >= all->info.y)
		all->spr.draw_end_y = all->info.y - 1;
	all->spr.sprite_width = abs((int)(all->info.y / (all->spr.tran_y)));
	all->spr.draw_start_x = -all->spr.sprite_width / 2 + all->spr.spr_screen_x;
	if (all->spr.draw_start_x < 0)
		all->spr.draw_start_x = 0;
	all->spr.draw_end_x = all->spr.sprite_width / 2 + all->spr.spr_screen_x;
	if (all->spr.draw_end_x >= all->info.x)
		all->spr.draw_end_x = all->info.x - 1;
	all->spr.stripe = all->spr.draw_start_x;
}

static void			draw_sprite(t_all *all, int y)
{
	int				d;
	unsigned int	color;

	d = y * 256 - all->info.y * 128 + all->spr.sprite_height * 128;
	all->tex.tex_y = ((d * all->sprite_texture.height) /\
		all->spr.sprite_height) / 256;
	color = my_mlx_pixel_take(&all->sprite_texture, all->tex.tex_x,\
		all->tex.tex_y);
	if (color)
		my_mlx_pixel_put(all, all->spr.stripe, y, color);
}

static void			sprite(t_all *all, double *zbuffer)
{
	int		y;

	all->tex.tex_x = (int)(256 * (all->spr.stripe -\
		(-all->spr.sprite_width / 2 + all->spr.spr_screen_x)) *\
		all->sprite_texture.width / all->spr.sprite_width) / 256;
	if (all->spr.tran_y > 0 && all->spr.stripe > 0 && all->spr.stripe <\
		all->info.x && all->spr.tran_y < zbuffer[all->spr.stripe])
	{
		y = all->spr.draw_start_y;
		while (y < all->spr.draw_end_y)
			draw_sprite(all, y++);
	}
}

void				init_sprite(t_all *all, double *zbuffer)
{
	int				i;
	double			spritedistance[all->map.num];

	sprite_dist(all, spritedistance);
	sort_sprites(all);
	i = 0;
	while (i < all->map.num)
	{
		calc_sprite(all, i);
		while (all->spr.stripe < all->spr.draw_end_x)
		{
			sprite(all, zbuffer);
			all->spr.stripe++;
		}
		i++;
	}
}
