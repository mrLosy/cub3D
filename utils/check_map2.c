/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 03:47:09 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 09:02:17 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	position_player(t_all *all, int h, int i)
{
	all->map.player_x = h + 0.5;
	all->map.player_y = i + 0.5;
	if (all->map.map[h][i] == 'S')
		all->map.player_n = 3;
	else if (all->map.map[h][i] == 'N')
		all->map.player_n = 4;
	else if (all->map.map[h][i] == 'W')
		all->map.player_n = 5;
	else if (all->map.map[h][i] == 'E')
		all->map.player_n = 6;
	all->map.map[h][i] = '0';
	return (1);
}

int			ft_error_map(t_all *all)
{
	int		i;
	int		h;

	i = 1;
	h = 0;
	all->error.error += ft_check_first_char(all);
	while (h < all->map.y)
	{
		if (h == 0 || (h + 1) == all->map.y)
			all->error.error += ft_check_line(all->map.map[h]);
		else
		{
			while (all->map.map[h][i] != '\0')
			{
				if (all->map.map[h][i] == '0' || all->map.map[h][i] == '2' || \
					all->map.map[h][i] == 'N' || all->map.map[h][i] == 'W' || \
					all->map.map[h][i] == 'S' || all->map.map[h][i] == 'E')
					all->error.error += ft_check_map(all, h, i);
				i++;
			}
		}
		h++;
		i = 1;
	}
	return (all->error.error);
}

static int	ft_check_position(t_all *all)
{
	int		i;
	int		h;

	h = 0;
	i = 0;
	while (h < all->map.y)
	{
		while (all->map.map[h][i] != '\0')
		{
			if (all->map.map[h][i] == 'N' || all->map.map[h][i] == 'S' || \
				all->map.map[h][i] == 'W' || all->map.map[h][i] == 'E')
				all->map.position += position_player(all, h, i);
			i++;
		}
		h++;
		i = 1;
	}
	if (all->map.position != 1)
		return (1);
	return (0);
}

static int	ft_check_c(t_all *all, int h, int i)
{
	int		error;
	int		a;

	a = 1;
	error = 0;
	all->error.error += ft_check_position(all);
	while (a > -2)
	{
		if (all->map.map[h][i - a] != '0' && all->map.map[h][i - a] != '1' &&\
		all->map.map[h][i - a] != '2' && all->map.map[h][i - a] != 'N' &&\
		all->map.map[h][i - a] != 'S' && all->map.map[h][i - a] != 'W' &&\
		all->map.map[h][i - a] != 'E' && all->map.map[h][i - a] != ' ' &&\
		all->map.map[h][i - a] != '\n')
			error++;
		a -= 2;
	}
	return (error);
}

int			ft_error_c(t_all *all)
{
	int		i;
	int		h;

	i = 1;
	h = 0;
	while (h < all->map.y)
	{
		while (all->map.map[h][i] != '\0' && all->map.map[h][i + 1] != '\0')
		{
			if (all->map.map[h][i] == '1')
				all->error.error += ft_check_c(all, h, i);
			i++;
		}
		h++;
		i = 1;
	}
	return (all->error.error);
}
