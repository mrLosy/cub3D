/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:37:35 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 08:56:50 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_reset_struct_2(t_all *all)
{
	all->tex.tex_x = 0;
	all->tex.tex_y = 0;
	all->tex.endian = 0;
	all->tex.width = 0;
	all->tex.height = 0;
	all->tex.step = 0;
	all->tex.tex_pos = 0;
	all->color.i = 0;
	all->color.h = 0;
	all->color.factor = 0;
	all->color.color = 0;
	all->map.player_x = 0;
	all->map.player_y = 0;
	all->map.player_n = 0;
	all->map.position = 0;
	all->map.check = 0;
	all->map.num = 0;
	all->map.len = 0;
	all->map.map = NULL;
	all->s = NULL;
}

static void	ft_reset_struct(t_all *all)
{
	ft_reset_struct_2(all);
	all->map.position = 0;
	all->error.error = 0;
	all->map.x = 0;
	all->map.y = 0;
	all->info.x = 0;
	all->info.y = 0;
	all->info.f = 0;
	all->info.c = 0;
	all->info.bufmap = NULL;
	all->info.line = 0;
	all->rayc.pos_x = 0;
	all->rayc.pos_y = 0;
	all->rayc.dir_x = 0;
	all->rayc.dir_y = 0;
	all->rayc.ray_x = 0;
	all->rayc.ray_y = 0;
	all->rayc.side = 0;
	all->rayc.plane_x = 0;
	all->rayc.plane_y = 0;
	all->rayc.time = 0;
	all->rayc.oldtime = 0;
	all->vars.win = NULL;
	all->vars.mlx = NULL;
}

void		ft_parsing(t_all *all, char *line, int i)
{
	if (line[i] == 'R' && line[i + 1] == ' ')
		ft_resolution(all, line);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		all->info.no = ft_texture(all, line);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		all->info.so = ft_texture(all, line);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		all->info.we = ft_texture(all, line);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		all->info.ea = ft_texture(all, line);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		all->info.s = ft_texture(all, line);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		all->info.f = ft_color(all, line);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		all->info.c = ft_color(all, line);
	else if (line[i] == '1' || line[i] == '0' || line[i] == '2' ||\
			line[i] == ' ')
		ft_scanmap(all, line);
	else if ((line[i] == '\0' || line[i]) && all->map.y > 1)
		ft_new_line_check(all, line);
	else if (line[i] && line[i] != '\0')
		ft_error("Error\n in map.cub\n(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧\n");
	else
		free(line);
}

void		ft_valid_map(t_all *all)
{
	all->map.map = ft_split(all->info.bufmap, '+');
	free(all->info.bufmap);
	ft_space_add(all);
	if (ft_error_map(all) > 0 || all->map.check > 0 || ft_error_c(all) > 0)
	{
		ft_error("Error\n in map\n( ＾▽＾)っ✂╰⋃╯\n");
	}
}

void		parser(t_all *all, char **argv)
{
	int		fd;
	char	*line;
	int		h;
	int		i;

	line = NULL;
	ft_reset_struct(all);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Error\n in fd\n( • )( • )ԅ(≖‿≖ԅ)\n");
	while ((h = get_next_line(fd, &line)) > 0)
	{
		if (h == -1)
			ft_error("Error\n in gnl\n♡ (˘▽˘>ԅ( ˘⌣˘)\n");
		i = 0;
		ft_parsing(all, line, i);
	}
	close(fd);
	ft_parsing(all, line, i);
	ft_valid_map(all);
	ft_search_sprites(all);
}
