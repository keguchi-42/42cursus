/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:49:45 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/07 21:46:02 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_linux.h"

void	draw_half_window(t_info *info, int x, int y, int win)
{
	int	color;

	color = 0;
	if (win == info->win_height)
		color = info->map.f_color;
	else
		color = info->map.c_color;
	while (y < info->win_width)
	{
		info->buf[x][y] = color;
		y++;
	}
}

void	drawing_sprite(t_info *info, t_calc_sp *calc_sp, int x, int y)
{
	calc_sp->tex_x = (int)(((y - (-calc_sp->sprite_width / 2
						+ calc_sp->sprite_screen_x))
				* TEX_WIDTH / calc_sp->sprite_width));
	if (calc_sp->new_y > 0 && y >= 0
		&& y < info->win_width && calc_sp->new_y < info->z_buffer[y])
	{
		x = calc_sp->draw_start_y;
		while (x < calc_sp->draw_end_y)
		{
			calc_sp->tex_y = (((x * 2 - info->win_height
							+ calc_sp->sprite_height) * TEX_HEIGHT)
					/ calc_sp->sprite_height) / 2;
			if (info->texture[4]
				[TEX_WIDTH * calc_sp->tex_y + calc_sp->tex_x] > 0)
				info->buf[x][y] = info->texture[4][TEX_WIDTH
					* calc_sp->tex_y + calc_sp->tex_x];
			x++;
		}
	}
}
