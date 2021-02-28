/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 17:58:05 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 21:08:26 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		key_hook_fourth(int i, t_all *all, float move)
{
	if (i == 13)
	{
		if (all->map.map[(int)(all->map.player_x + all->rayc.dir_x *\
			move)][(int)(all->map.player_y)] == '0')
			all->map.player_x += all->rayc.dir_x * move;
		if (all->map.map[(int)(all->map.player_x)][(int)\
			(all->map.player_y + all->rayc.dir_y * move)] == '0')
			all->map.player_y += all->rayc.dir_y * move;
	}
	else if (i == 1)
	{
		if (all->map.map[(int)(all->map.player_x - all->rayc.dir_x * move)]\
				[(int)(all->map.player_y)] == '0')
			all->map.player_x -= all->rayc.dir_x * move;
		if (all->map.map[(int)(all->map.player_x)][(int)(all->map.player_y -\
				all->rayc.dir_y * move)] == '0')
			all->map.player_y -= all->rayc.dir_y * move;
	}
}

static void		key_hook_third(int keycode, t_all *all, float move)
{
	if (keycode == 0)
	{
		if (all->map.map[(int)(all->map.player_x)][(int)(all->map.player_y +\
				all->rayc.dir_x * move)] == '0')
			all->map.player_y += all->rayc.dir_x * move;
		if (all->map.map[(int)(all->map.player_x - all->rayc.dir_y * move)]\
				[(int)(all->map.player_y)] == '0')
			all->map.player_x -= all->rayc.dir_y * move;
	}
	else if (keycode == 2)
	{
		if (all->map.map[(int)(all->map.player_x)][(int)(all->map.player_y -\
				all->rayc.dir_x * move)] == '0')
			all->map.player_y -= all->rayc.dir_x * move;
		if (all->map.map[(int)(all->map.player_x + all->rayc.dir_y * move)]\
				[(int)(all->map.player_y)] == '0')
			all->map.player_x += all->rayc.dir_y * move;
	}
}

static void		key_hook_sec(int keycode, t_all *all, float rot)
{
	if (keycode == 123)
	{
		all->rayc.dir_x = all->rayc.dir_x * cos(rot) -\
			all->rayc.dir_y * sin(rot);
		all->rayc.dir_y = all->rayc.dir_x * sin(rot) +\
			all->rayc.dir_y * cos(rot);
		all->rayc.plane_x = all->rayc.plane_x * cos(rot) -\
			all->rayc.plane_y * sin(rot);
		all->rayc.plane_y = all->rayc.plane_x * sin(rot) +\
			all->rayc.plane_y * cos(rot);
	}
	else if (keycode == 124)
	{
		all->rayc.dir_x = all->rayc.dir_x * cos(-rot) -\
			all->rayc.dir_y * sin(-rot);
		all->rayc.dir_y = all->rayc.dir_x * sin(-rot) +\
			all->rayc.dir_y * cos(-rot);
		all->rayc.plane_x = all->rayc.plane_x * cos(-rot) -\
			all->rayc.plane_y * sin(-rot);
		all->rayc.plane_y = all->rayc.plane_x * sin(-rot) +\
			all->rayc.plane_y * cos(-rot);
	}
}

static void		create_image(t_all *all)
{
	mlx_destroy_image(all->vars.mlx, all->data.img);
	if (!(all->data.img = mlx_new_image(all->vars.mlx, all->info.x,\
		all->info.y)))
		ft_error("Error\n in mlx\n(；￣Д￣)\n");
	if (!(all->data.addr = mlx_get_data_addr(all->data.img,\
		&all->data.bits_per_pixel, &all->data.line_length, &all->data.endian)))
		ft_error("Error\n in mlx\n(；￣Д￣)\n");
	raycast(all);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win,\
		all->data.img, 0, 0);
}

int				key_hook(int keycode, t_all *all)
{
	float		move;
	float		rot;

	move = 0.1;
	rot = 0.1;
	if (keycode == 53)
		exit(1);
	if (keycode == 13)
		key_hook_fourth(13, all, 0.1);
	else if (keycode == 1)
		key_hook_fourth(1, all, 0.1);
	else if (keycode == 2)
		key_hook_third(2, all, 0.1);
	else if (keycode == 0)
		key_hook_third(0, all, 0.1);
	else if (keycode == 124)
		key_hook_sec(124, all, 0.1);
	else if (keycode == 123)
		key_hook_sec(123, all, 0.1);
	create_image(all);
	return (1);
}
