/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haristot <haristot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 08:17:37 by haristot          #+#    #+#             */
/*   Updated: 2021/02/27 21:02:56 by haristot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		ft_check_res(t_all *all)
{
	int		i;
	int		y;

	mlx_get_screen_size(all->vars.mlx, &i, &y);
	if (all->info.x > i)
		all->info.x = i;
	if (all->info.y > y)
		all->info.y = y;
}
