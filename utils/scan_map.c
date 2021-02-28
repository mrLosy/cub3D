/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 03:42:02 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 21:52:36 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_checker_map(char *line)
{
	int i;
	int h;

	h = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '2' || line[i] == 'N' ||\
			line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		{
			if (line[i - 1] == ' ' || line[i + 1] == ' ')
			{
				ft_error("Error\n in map\n≧( ° ° )≦\n");
				h = 1;
			}
		}
		i++;
	}
	return (h);
}

static void	ft_separation(t_all *all, char *linemap)
{
	if (all->info.line != 8)
		ft_error("Error\n in map.cub\n٩(｡•́‿•̀｡)۶");
	if ((int)ft_strlen(linemap) > all->map.len)
		all->map.len = ft_strlen(linemap);
	if (!(all->map.str = ft_strdup_n(linemap)))
		ft_error("Error\nError in malloc\n");
	free(linemap);
}

void		ft_scanmap(t_all *all, char *line)
{
	char	*str;
	int		i;

	i = 0;
	ft_skipspace(line, &i);
	if (!line[i] && all->map.y < 1)
		ft_error("Error\nin map.cub\n");
	if (all->map.len < (int)ft_strlen(line))
		all->map.len = ft_strlen(line);
	ft_separation(all, line);
	if (ft_checker_map(all->map.str) == 0)
	{
		if (all->map.y == 0)
			all->info.bufmap = ft_strdup(all->map.str);
		else
		{
			str = all->info.bufmap;
			all->info.bufmap = ft_strjoin(all->info.bufmap, all->map.str);
			free(str);
		}
		free(all->map.str);
		all->map.y += 1;
		if (!(all->info.bufmap))
			ft_error("Error\nError in malloc\n");
	}
}

void		ft_new_line_check(t_all *all, char *line)
{
	int		i;
	char	*linemap;

	i = 0;
	if (line[0] == '\0' || line[0] == '\n')
		ft_error("Error\n in map\n(つ . •́ _ʖ •̀ .)つ");
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '2' && line[i] != '0' &&\
			line[i] != 'S' && line[i] != 'N' && line[i] != 'W' &&\
			line[i] != 'E' && line[i] != ' ')
			all->map.check++;
		i++;
	}
	all->map.y++;
	if (!(linemap = ft_calloc(sizeof(char *), all->map.len)))
		ft_error("Error\nIn calloc\n");
	i = 0;
	while (i < all->map.len)
		linemap[i++] = ' ';
	linemap[--i] = '+';
	if (!(all->info.bufmap = ft_strjoin(all->info.bufmap, linemap)))
		ft_error("Error\nIn strjoin\n");
	free(linemap);
	free(line);
}

void		ft_space_add(t_all *all)
{
	int		h;
	char	*ptr;
	int		i;
	char	*str;

	h = 0;
	i = 0;
	while (h < all->map.y)
	{
		if ((i = ft_strlen(all->map.map[h])) < all->map.len)
		{
			ptr = all->map.map[h];
			str = ft_calloc(sizeof(char *), all->map.len - i + 1);
			i = all->map.len - i;
			while ((i) >= 0)
				str[i--] = ' ';
			all->map.map[h] = ft_strjoin(ptr, str);
			free(ptr);
			free(str);
		}
		h++;
	}
}
