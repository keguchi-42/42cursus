/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:25:05 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/05 02:59:14 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_mac.h"

void	init_zbuf(t_info *info)
{
	int	i;

	i = 0;
	info->z_buffer = malloc(sizeof(double) * (info->win_width));
	if (!(info->z_buffer))
		error_exit(MALLOC_ERROR);
	while (i < info->win_width)
	{
		info->z_buffer[i] = 0;
		i++;
	}
}

void	init_buf(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	info->buf = malloc(sizeof(int *) * (info->win_height + 1));
	if (!(info->buf))
		error_exit(MALLOC_ERROR);
	while (i < info->win_height)
	{
		info->buf[i] = malloc(sizeof(int) * (info->win_width));
		if (!(info->buf[i]))
			error_exit(MALLOC_ERROR);
		j = 0;
		while (j < info->win_width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	info->buf[i] = NULL;
}

void	init_max(t_info *info, int *max_width, int *max_height)
{
	*max_width = 0;
	*max_height = 0;
	mlx_get_screen_size(info->mlx, max_width, max_height);
}
