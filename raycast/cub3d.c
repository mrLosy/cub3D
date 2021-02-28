/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:45:43 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 21:48:07 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void			my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->data.addr + (y * all->data.line_length +\
	x * (all->data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int		close_win(void)
{
	ft_error("Close window\n(* ^ ω ^)\n");
	return (1);
}

void			init_game(t_all *all)
{
	ft_check_res(all);
	if (!(all->vars.mlx = mlx_init()))
		ft_error("Error\nmlx\n(；￣Д￣)\n");
	filling_texture_img(all);
	if (!(all->vars.win = mlx_new_window(all->vars.mlx, all->info.x,\
		all->info.y, "Putin krutoi, a Navalnyi net!")))
		ft_error("Error\nmlx\n(；￣Д￣)\n");
	if (!(all->data.img = mlx_new_image(all->vars.mlx, all->info.x,\
		all->info.y)))
		ft_error("Error\nmlx\n(；￣Д￣)\n");
	if (!(all->data.addr = mlx_get_data_addr(all->data.img,\
		&all->data.bits_per_pixel, &all->data.line_length, &all->data.endian)))
		ft_error("Error\nmlx\n(；￣Д￣)\n");
	raycast(all);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win,\
		all->data.img, 0, 0);
	mlx_hook(all->vars.win, 2, 1L << 0, key_hook, all);
	mlx_hook(all->vars.win, 17, 1L << 0, close_win, all);
	if (!(mlx_loop(all->vars.mlx)))
		ft_error("Error\nmlx\n(；￣Д￣)\n");
}

static void		ft_check_argv(char *line)
{
	int		i;
	char	*str;
	int		h;

	h = 3;
	if (!(str = ft_strdup(".cub")))
		ft_error("Error\nmalloc\n");
	if ((i = ft_strlen(line)) < 5)
		ft_error("Error\nNo config file\n");
	i--;
	while (h > -1)
	{
		if (str[h--] != line[i--])
			ft_error("Error\nNo *.cub\n");
	}
	free(str);
}

int				main(int argc, char **argv)
{
	t_all		all;

	parser(&all, argv);
	side_plr(&all);
	if (argc == 2)
	{
		ft_check_argv(argv[1]);
		init_game(&all);
	}
	else if (argc == 3)
		save_scrin(&all, argv[2]);
	else
		ft_error("Error\nargv\n(；￣Д￣)\n");
	return (0);
}
