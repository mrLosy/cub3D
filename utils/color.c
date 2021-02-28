/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 03:40:20 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 08:57:49 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_skipspace(char *line, int *i)
{
	while (line[*i] == '\r' || line[*i] == '\v' \
			|| line[*i] == '\f' || line[*i] == ' ')
		*i += 1;
}

int			checker_color_sec(char *line, int i)
{
	int		warn;
	int		y;

	warn = 0;
	y = 0;
	if (ft_atoi(&line[i]) > 255 || ft_atoi(&line[i]) < 0)
		warn++;
	if (!(ft_isdigit(line[i])))
		warn++;
	while (ft_isdigit(line[i]))
	{
		i++;
		y++;
	}
	if (line[i] != '\0' || y > 3)
		warn++;
	else
		i++;
	ft_skipspace(line, &i);
	return (warn);
}

int			checker_color(t_all *all, char *line, int i)
{
	int		h;
	int		y;

	h = 0;
	while (h < 2)
	{
		y = 0;
		if (ft_atoi(&line[i]) > 255 || ft_atoi(&line[i]) < 0)
			all->map.check++;
		if (!(ft_isdigit(line[i])))
			all->map.check++;
		while (ft_isdigit(line[i]))
		{
			i++;
			y++;
		}
		if ((line[i] != ',' && line[i] != '\0') || y > 3)
			all->map.check++;
		i++;
		ft_skipspace(line, &i);
		h++;
	}
	all->map.check += checker_color_sec(line, i);
	return (all->map.check);
}

static void	ft_reset_color(t_all *all)
{
	all->color.color = 0;
	all->color.factor = 65536;
	all->color.i = 1;
	all->color.h = 0;
}

int			ft_color(t_all *all, char *line)
{
	all->info.line++;
	ft_reset_color(all);
	ft_skipspace(line, &all->color.i);
	if (checker_color(all, line, all->color.i) == 0)
	{
		while (all->color.h < 3)
		{
			all->color.color += (ft_atoi(&line[all->color.i])\
				* all->color.factor);
			while (ft_isdigit(line[all->color.i]))
				all->color.i++;
			ft_skipspace(line, &all->color.i);
			all->color.i++;
			ft_skipspace(line, &all->color.i);
			all->color.factor /= 256;
			all->color.h++;
		}
	}
	else
		ft_error("Error\n in colors\n(๑˘︶˘๑)\n");
	free(line);
	return (all->color.color);
}
