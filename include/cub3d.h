/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 23:48:49 by haristot          #+#    #+#             */
/*   Updated: 2021/03/08 16:06:38 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct		s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_data;

typedef struct		s_vars
{
	void		*mlx;
	void		*win;
}					t_vars;

typedef struct		s_error
{
	int		h;
	int		i;
	int		error;
}					t_error;

typedef struct		s_sprite
{
	float		x;
	float		y;
	float		dis;
}					t_sprite;

typedef struct		s_info
{
	int				x;
	int				y;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	unsigned int	f;
	unsigned int	c;
	char			*bufmap;
	int				line;
}					t_info;

typedef struct		s_map
{
	int				x;
	int				y;
	float			player_x;
	float			player_y;
	int				player_n;
	int				position;
	int				check;
	int				num;
	int				len;
	char			**map;
	char			*str;
}					t_map;

typedef struct		s_color
{
	int				i;
	int				h;
	int				factor;
	unsigned int	color;
}					t_color;

typedef struct		s_rayc
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	ray_x;
	float	ray_y;
	int		side;
	float	plane_x;
	float	plane_y;
	float	time;
	float	oldtime;
	int		map_x;
	int		map_y;
	void	*mlx_win;
	float	movespeed;
}					t_rayc;

typedef struct		s_img
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}					t_img;

typedef struct		s_tex
{
	int			tex_x;
	int			tex_y;
	int			endian;
	int			width;
	int			height;
	int			l_height;
	double		step;
	double		tex_pos;
}					t_tex;

typedef struct		s_spr
{
	double		sprite_x;
	double		sprite_y;
	double		tran_x;
	double		tran_y;
	double		inv_det;
	int			spr_screen_x;
	int			sprite_height;
	int			draw_start_y;
	int			draw_end_y;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
	int			stripe;
}					t_spr;

typedef struct		s_r
{
	int				x;
	int				y;
	unsigned int	color;
	double			wall_x;
	float			camera_x;
	int				map_x;
	int				map_y;
	float			side_dist_x;
	float			side_dist_y;
	float			delta_dist_x;
	float			delta_dist_y;
	float			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				draw_start;
	int				draw_end;
}					t_r;

typedef struct		s_all
{
	t_info		info;
	t_map		map;
	t_color		color;
	t_rayc		rayc;
	t_vars		vars;
	t_data		data;
	t_img		north_texture;
	t_img		south_texture;
	t_img		west_texture;
	t_img		east_texture;
	t_img		sprite_texture;
	t_tex		tex;
	t_error		error;
	t_sprite	*s;
	t_spr		spr;
	t_r			r;
}					t_all;

void				parser(t_all *all, char **argv);
void				ft_skipspace(char *line, int *i);
void				ft_resolution(t_all *all, char *line);
char				*ft_texture(t_all *all, char *line);
int					ft_color(t_all *all, char *line);
int					checker_color_sec(char *line, int i);
int					checker_color(t_all *all, char *line, int i);
void				ft_scanmap(t_all *all, char *line);
void				ft_new_line_check(t_all *all, char *line);
int					ft_check_first_char(t_all *all);
int					ft_check_line(char *line);
int					ft_check_map(t_all *all, int h, int i);
int					ft_error_map(t_all *all);
int					ft_error_c(t_all *all);
void				ft_search_sprites(t_all *all);
void				ft_space_add(t_all *all);
void				raycast(t_all *all);
int					key_hook(int keycode, t_all *all);
void				filling_texture_img(t_all *all);
void				save_scrin(t_all *all, char *line);
unsigned int		my_mlx_pixel_take(t_img *img, int x, int y);
void				side_plr(t_all *all);
void				calculat_pos(t_all *all, t_img *img,\
					double wall_x, int draw);
void				filling_texture_img(t_all *all);
void				sort_sprites(t_all *all);
void				init_sprite(t_all *all, double *zbuffer);
void				my_mlx_pixel_put(t_all *all, int x, int y, int color);
void				raycast(t_all *all);
void				pixel_put_sec(t_all *all);
void				pixel_put_fir(t_all *all);
void				calc_draw(t_all *all);
void				calc_step(t_all *all);
void				calc_side(t_all *all);
void				calc_draw_fir(t_all *all);
void				calc_step_fir(t_all *all);
void				ft_check_res(t_all *all);

#endif
