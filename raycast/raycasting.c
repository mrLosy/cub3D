/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:15:08 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 06:33:34 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void			calc_step_fir(t_all *all)
{
	calc_step(all);
	if (all->rayc.ray_x < 0)
	{
		all->r.step_x = -1;
		all->r.side_dist_x = (all->map.player_x - all->r.map_x)\
			* all->r.delta_dist_x;
	}
	else
	{
		all->r.step_x = 1;
		all->r.side_dist_x = (all->r.map_x + 1.0 - all->map.player_x)\
			* all->r.delta_dist_x;
	}
	if (all->rayc.ray_y < 0)
	{
		all->r.step_y = -1;
		all->r.side_dist_y = (all->map.player_y - all->r.map_y)\
			* all->r.delta_dist_y;
	}
	else
	{
		all->r.step_y = 1;
		all->r.side_dist_y = (all->r.map_y + 1.0 - all->map.player_y)\
			* all->r.delta_dist_y;
	}
}

void			calc_draw_fir(t_all *all)
{
	calc_draw(all);
	if (all->rayc.side == 0)
	{
		if (all->r.step_x > 0)
			calculat_pos(all, &all->north_texture, all->r.wall_x,\
				all->r.draw_start);
		else if (all->r.step_x < 0)
			calculat_pos(all, &all->south_texture, all->r.wall_x,\
				all->r.draw_start);
	}
	if (all->rayc.side == 1)
	{
		if (all->r.step_y > 0)
			calculat_pos(all, &all->west_texture, all->r.wall_x,\
				all->r.draw_start);
		else if (all->r.step_y < 0)
			calculat_pos(all, &all->east_texture, all->r.wall_x,\
				all->r.draw_start);
	}
}

void			calc_side(t_all *all)
{
	all->r.hit = 0;
	while (all->r.hit == 0)
	{
		if (all->r.side_dist_x < all->r.side_dist_y)
		{
			all->r.side_dist_x += all->r.delta_dist_x;
			all->r.map_x += all->r.step_x;
			all->rayc.side = 0;
		}
		else
		{
			all->r.side_dist_y += all->r.delta_dist_y;
			all->r.map_y += all->r.step_y;
			all->rayc.side = 1;
		}
		if (all->map.map[(int)all->r.map_x][all->r.map_y] == '1')
			all->r.hit = 1;
	}
	if (all->rayc.side == 0)
		all->r.perp_wall_dist = (all->r.map_x - all->map.player_x\
			+ (1 - all->r.step_x) / 2) / all->rayc.ray_x;
	else
		all->r.perp_wall_dist = (all->r.map_y - all->map.player_y\
			+ (1 - all->r.step_y) / 2) / all->rayc.ray_y;
}

void			pixel_put(t_all *all)
{
	if (all->r.y < all->r.draw_start)
		my_mlx_pixel_put(all, all->r.x, all->r.y, all->info.c);
	else if (all->r.y >= all->r.draw_start && all->r.y <= all->r.draw_end)
	{
		all->tex.tex_y = all->tex.tex_pos;
		all->tex.tex_pos += all->tex.step;
		if (all->rayc.side == 0)
			pixel_put_fir(all);
		if (all->rayc.side == 1)
			pixel_put_sec(all);
	}
	else if (all->r.y > all->r.draw_end)
		my_mlx_pixel_put(all, all->r.x, all->r.y, all->info.f);
	all->r.y++;
}

void			raycast(t_all *all)
{
	double		zbuffer[all->info.x];

	all->r.x = 0;
	while (all->r.x < all->info.x)
	{
		calc_step_fir(all);
		calc_side(all);
		calc_draw_fir(all);
		all->r.y = 0;
		while (all->r.y < all->info.y)
			pixel_put(all);
		zbuffer[all->r.x] = all->r.perp_wall_dist;
		all->r.x++;
	}
	init_sprite(all, zbuffer);
}
