/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 03:34:34 by haristot          #+#    #+#             */
/*   Updated: 2021/03/08 16:07:09 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	res(t_all *all, char *line, int i)
{
	int		h;

	h = 0;
	i = 2;
	ft_skipspace(line, &i);
	while (line[i] == '0')
		i++;
	while (ft_isdigit(line[i]))
	{
		i++;
		h++;
	}
	if (h > 5)
		all->info.x = 99999;
	ft_skipspace(line, &i);
	h = 0;
	while (line[i] == '0')
		i++;
	while (ft_isdigit(line[i]))
	{
		i++;
		h++;
	}
	if (h > 5)
		all->info.y = 99999;
}

static int	ft_res_check(t_all *all, char *line, int i)
{
	int		h;
	int		y;

	y = 0;
	h = 0;
	if (all->info.x < 1 || all->info.y < 1)
		h++;
	while (ft_isdigit(line[i]))
		i++;
	ft_skipspace(line, &i);
	if (line[i] != '\0')
		h++;
	return (h);
}

void		ft_resolution(t_all *all, char *line)
{
	int		i;

	i = 0;
	all->info.line++;
	ft_skipspace(line, &i);
	all->info.x = ft_atoi(&line[++i]);
	i++;
	while (ft_isdigit(line[i]))
		i++;
	ft_skipspace(line, &i);
	all->info.y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	res(all, line, i);
	if (ft_res_check(all, line, i) > 0)
		ft_error("Error\n in resolution\n(▽◕ ᴥ ◕▽)\n");
	free(line);
}

static void	ft_checker_texture(char *line, int i)
{
	char	*str;
	int		h;

	if (line[i] == '.' && line[i + 1] == '/')
		i += 2;
	while (ft_isprint_s(line[i]))
		i++;
	if (line[i] != '\0')
		ft_error("Error\n in texture\n∪◣_◢∪\n");
	if (!(str = ft_strdup(".xpm")))
		ft_error("Error\nError in malloc\n");
	h = 3;
	while (h > -1)
	{
		if (str[h--] != line[--i])
			ft_error("Error\n.xpm error\n∪◣_◢∪\n");
	}
	free(str);
}

char		*ft_texture(t_all *all, char *line)
{
	char	*dst;
	int		i;

	all->info.line++;
	i = 2;
	ft_skipspace(line, &i);
	ft_checker_texture(line, i);
	if (!(dst = ft_strdup(&line[i])))
		ft_error("Error\n in map\n(￣(00)￣)\n");
	free(line);
	return (dst);
}
