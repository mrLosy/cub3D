/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:45:21 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 04:36:13 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		fil_tex_img(t_all *all)
{
	if (!(all->west_texture.addr = mlx_get_data_addr(all->west_texture.img,\
		&all->west_texture.bits_per_pixel, &all->west_texture.line_length,\
		&all->west_texture.endian)))
		ft_error("Error\n in mlx\n(；￣Д￣)\n");
	if (!(all->east_texture.img = mlx_xpm_file_to_image(all->vars.mlx,\
		all->info.ea, &all->east_texture.width, &all->east_texture.height)))
		ft_error("Error\n in east texture\n( *^^)o∀*∀o(^^* )\n");
	if (!(all->east_texture.addr = mlx_get_data_addr(all->east_texture.img,\
		&all->east_texture.bits_per_pixel, &all->east_texture.line_length,\
		&all->east_texture.endian)))
		ft_error("Error\n in mlx\n(；￣Д￣)\n");
	if (!(all->sprite_texture.img = mlx_xpm_file_to_image(all->vars.mlx,\
		all->info.s, &all->sprite_texture.width, &all->sprite_texture.height)))
		ft_error("Error\n in sprite texture\n( *^^)o∀*∀o(^^* )\n");
	if (!(all->sprite_texture.addr = mlx_get_data_addr(all->sprite_texture.img,\
		&all->sprite_texture.bits_per_pixel, &all->sprite_texture.line_length,\
		&all->sprite_texture.endian)))
		ft_error("Error\n in mlx\n(；￣Д￣)\n");
}

void			filling_texture_img(t_all *all)
{
	if (!(all->north_texture.img = mlx_xpm_file_to_image(all->vars.mlx,\
		all->info.no, &all->north_texture.width, &all->north_texture.height)))
		ft_error("Error\n in north texture\n( *^^)o∀*∀o(^^* )\n");
	if (!(all->north_texture.addr = mlx_get_data_addr(all->north_texture.img,\
		&all->north_texture.bits_per_pixel, &all->north_texture.line_length,\
		&all->north_texture.endian)))
		ft_error("Error\n in mlx\n(；￣Д￣)\n");
	if (!(all->south_texture.img = mlx_xpm_file_to_image(all->vars.mlx,\
		all->info.so, &all->south_texture.width, &all->south_texture.height)))
		ft_error("Error\n in south texture\n( *^^)o∀*∀o(^^* )\n");
	if (!(all->south_texture.addr = mlx_get_data_addr(all->south_texture.img,\
		&all->south_texture.bits_per_pixel, &all->south_texture.line_length,\
		&all->south_texture.endian)))
		ft_error("Error\n in mlx\n(；￣Д￣)\n");
	if (!(all->west_texture.img = mlx_xpm_file_to_image(all->vars.mlx,\
		all->info.we, &all->west_texture.width, &all->west_texture.height)))
		ft_error("Error\n in west texture\n( *^^)o∀*∀o(^^* )\n");
	fil_tex_img(all);
}

void			calculat_pos(t_all *all, t_img *img, double wall_x, int draw)
{
	all->tex.tex_x = (int)(wall_x * (double)(img->width));
	if (all->rayc.side == 0 && all->rayc.ray_x > 0)
		all->tex.tex_x = img->width - all->tex.tex_x - 1;
	if (all->rayc.side == 1 && all->rayc.ray_y < 0)
		all->tex.tex_x = img->width - all->tex.tex_x - 1;
	all->tex.step = 1.0 * img->height / all->tex.l_height;
	all->tex.tex_pos = (draw - all->info.y / 2 +\
		all->tex.l_height / 2) * all->tex.step;
}

void			side_plr(t_all *all)
{
	if (all->map.player_n == 3)
	{
		all->rayc.dir_x = -1;
		all->rayc.plane_y = 0.66;
	}
	else if (all->map.player_n == 4)
	{
		all->rayc.dir_x = 1;
		all->rayc.plane_y = -0.66;
	}
	else if (all->map.player_n == 6)
	{
		all->rayc.dir_y = -1;
		all->rayc.plane_x = -0.66;
	}
	else if (all->map.player_n == 5)
	{
		all->rayc.dir_y = 1;
		all->rayc.plane_x = 0.66;
	}
}

unsigned int	my_mlx_pixel_take(t_img *img, int x, int y)
{
	char	*dst;

	if (x >= 64)
		x = 63;
	if (y >= 64)
		y = 63;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}
