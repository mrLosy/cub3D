/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:34:42 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 08:48:29 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int		ft_check_argc(char *line)
{
	int		j;

	j = ft_strlen(line);
	if (ft_strncmp(line, "--save", j) == 0 && j == 6)
		return (0);
	else
		ft_error("Error\n in second argv\n(╮°-°)╮┳━━┳ ( ╯°□°)╯ ┻━━┻\n");
	return (0);
}

static void		create_screen(t_all *all, int fd)
{
	int		size_screen;
	int		pos_pixel_data;
	int		zero;
	short	plane;

	plane = 1;
	zero = 0;
	pos_pixel_data = 54;
	size_screen = all->info.x * all->info.y * 4 + 54;
	write(fd, "BM", 2);
	write(fd, &size_screen, 4);
	write(fd, &zero, 4);
	write(fd, &pos_pixel_data, 4);
	pos_pixel_data = 40;
	write(fd, &pos_pixel_data, 4);
	write(fd, &all->info.x, 4);
	write(fd, &all->info.y, 4);
	write(fd, &plane, 2);
	plane = 32;
	write(fd, &plane, 2);
}

static void		filling_file_screen(t_all *all, int fd)
{
	int	i;
	int	j;
	int	color;

	i = all->info.y;
	while (--i >= 0)
	{
		j = -1;
		while (++j < all->info.x)
		{
			color = *(int*)(all->data.addr + (i * all->data.line_length
					+ j * (all->data.bits_per_pixel / 8)));
			write(fd, &color, 4);
		}
	}
}

static void		screenshot(t_all *all)
{
	int fd;
	int size_screen;
	int zero;
	int size;

	if ((fd = open("screen.bmp", O_CREAT | O_RDWR, 0666)) < 0)
		ft_error("Error\n in fd screenshot\n‿︵‿ヽ(°□° )ノ︵‿︵\n");
	size_screen = all->info.x * all->info.y * 4 + 54;
	zero = 0;
	size = all->info.x * all->info.y;
	create_screen(all, fd);
	write(fd, &zero, 4);
	write(fd, &size, 4);
	size_screen = 1000;
	write(fd, &size_screen, 4);
	write(fd, &size_screen, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
	filling_file_screen(all, fd);
	close(fd);
}

void			save_scrin(t_all *all, char *line)
{
	ft_check_argc(line);
	if (!(all->vars.mlx = mlx_init()))
		ft_error("Error\n in mlx\n(；￣Д￣)\n");
	filling_texture_img(all);
	if (!(all->data.img = mlx_new_image(all->vars.mlx,\
		all->info.x, all->info.y)))
		ft_error("Error\n in mlx\n(；￣Д￣)\n");
	if (!(all->data.addr = mlx_get_data_addr(all->data.img,\
		&all->data.bits_per_pixel, &all->data.line_length, &all->data.endian)))
		ft_error("Error\n in mlx\n(；￣Д￣)\n");
	raycast(all);
	screenshot(all);
}
