/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:29:04 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 21:48:20 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*checker(char *buff, char **line)
{
	char	*buff2;
	char	*old_line;

	if (*buff)
	{
		old_line = *line;
		if ((buff2 = ft_strchr(buff, '\n')))
		{
			*buff2 = '\0';
			*line = ft_strjoin(*line, buff);
			ft_strcpy(buff, buff2 + 1);
		}
		else
		{
			*line = ft_strjoin(*line, buff);
			*buff = '\0';
		}
		free(old_line);
	}
	else
		buff2 = 0;
	return (buff2);
}

int				get_next_line(int fd, char **line)
{
	static char		buff[BUFFER_SIZE + 1] = "\0";
	int				h;
	char			*dst;

	if ((h = read(fd, buff, 0)) < 0 || BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (!(*line = ft_strdup("")))
		ft_error("Error\nGnl malloc error\n");
	dst = checker(buff, line);
	while (dst == 0 && (h = read(fd, buff, BUFFER_SIZE)))
	{
		buff[h] = '\0';
		dst = checker(buff, line);
	}
	return (dst == 0 && h == 0 ? 0 : 1);
}
