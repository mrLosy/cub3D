/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayc_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:24:32 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 00:26:01 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		calc_step(t_all *all)
{
	all->r.camera_x = 2 * all->r.x / (float)all->info.x - 1;
	all->rayc.ray_x = all->rayc.dir_x + all->rayc.plane_x * all->r.camera_x;
	all->rayc.ray_y = all->rayc.dir_y + all->rayc.plane_y * all->r.camera_x;
	all->r.map_x = (int)(all->map.player_x);
	all->r.map_y = (int)(all->map.player_y);
	all->r.delta_dist_x = sqrt(1 + (all->rayc.ray_y * all->rayc.ray_y) /\
		(all->rayc.ray_x * all->rayc.ray_x));
	all->r.delta_dist_y = sqrt(1 + (all->rayc.ray_x * all->rayc.ray_x) /\
		(all->rayc.ray_y * all->rayc.ray_y));
}

void		calc_draw(t_all *all)
{
	all->tex.l_height = (int)(all->info.y / all->r.perp_wall_dist);
	all->r.draw_start = -all->tex.l_height / 2 + all->info.y / 2;
	if (all->r.draw_start < 0)
		all->r.draw_start = 0;
	all->r.draw_end = all->tex.l_height / 2 + all->info.y / 2;
	if (all->r.draw_end >= all->info.y)
		all->r.draw_end = all->info.y - 1;
	if (all->rayc.side == 0)
		all->r.wall_x = all->map.player_y + all->r.perp_wall_dist *\
			all->rayc.ray_y;
	else
		all->r.wall_x = all->map.player_x + all->r.perp_wall_dist *\
			all->rayc.ray_x;
	all->r.wall_x -= floor((all->r.wall_x));
}

void		pixel_put_fir(t_all *all)
{
	if (all->r.step_x > 0)
	{
		all->r.color = my_mlx_pixel_take(&all->north_texture,\
			all->tex.tex_x, all->tex.tex_y);
		my_mlx_pixel_put(all, all->r.x, all->r.y, all->r.color);
	}
	else if (all->r.step_x < 0)
	{
		all->r.color = my_mlx_pixel_take(&all->south_texture,\
			all->tex.tex_x, all->tex.tex_y);
		my_mlx_pixel_put(all, all->r.x, all->r.y, all->r.color);
	}
}

void		pixel_put_sec(t_all *all)
{
	if (all->r.step_y > 0)
	{
		all->r.color = my_mlx_pixel_take(&all->west_texture,\
			all->tex.tex_x, all->tex.tex_y);
		my_mlx_pixel_put(all, all->r.x, all->r.y, all->r.color);
	}
	else if (all->r.step_y < 0)
	{
		all->r.color = my_mlx_pixel_take(&all->east_texture,\
			all->tex.tex_x, all->tex.tex_y);
		my_mlx_pixel_put(all, all->r.x, all->r.y, all->r.color);
	}
}
