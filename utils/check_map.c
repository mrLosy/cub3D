/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 03:44:04 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 08:45:14 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int			ft_check_first_char(t_all *all)
{
	int		i;
	int		h;
	int		error;

	error = 0;
	h = 0;
	i = 0;
	while (h < all->map.y)
	{
		ft_skipspace(all->map.map[h], &i);
		if (all->map.map[h][i] != '1' && all->map.map[h][i] != '\0')
			error++;
		h++;
		i = 0;
	}
	return (error);
}

int			ft_check_line(char *line)
{
	int		i;
	int		error;

	i = 0;
	error = 0;
	ft_skipspace(line, &i);
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ')
			error++;
		i++;
	}
	return (error);
}

static int	ft_check_utils(t_all *all, int h, int a, int i)
{
	if ((all->map.map[h][i - a] != '0' && all->map.map[h][i - a] != '1' &&\
		all->map.map[h][i - a] != '2' && all->map.map[h][i - a] != 'N' &&\
		all->map.map[h][i - a] != 'S' && all->map.map[h][i - a] != 'W' && \
		all->map.map[h][i - a] != 'E'))
		return (1);
	return (0);
}

int			ft_check_map(t_all *all, int h, int i)
{
	int		error;
	int		a;
	int		g;

	g = 0;
	a = 1;
	error = 0;
	h--;
	while (g < 3)
	{
		while (a != -2)
		{
			error += ft_check_utils(all, h, a, i);
			a--;
		}
		a = 1;
		h += 1;
		g++;
	}
	return (error);
}
