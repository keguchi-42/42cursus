/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 07:31:09 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/12 16:13:17 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_mac.h"

void	draw_sprite(t_info *info, t_sp *sprites, t_calc_sp *calc_sp)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < info->sprite_count)
	{
		set_sprite_elements1(info, sprites, calc_sp, i);
		y = calc_sp->draw_start_x;
		while (y < calc_sp->draw_end_x)
		{
			drawing_sprite(info, calc_sp, x, y);
			y++;
		}
		i++;
	}
}

void	draw_background(t_info *info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	calc_rgb(info);
	while (x < info->win_height / 2)
	{
		y = 0;
		draw_half_window(info, x, y, info->win_height / 2);
		x++;
	}
	while (x < info->win_height)
	{
		y = 0;
		draw_half_window(info, x, y, info->win_height);
		x++;
	}
}

void	get_texture_color(t_info *info, t_calc *calc, int *color)
{
	if (calc->side == 0 && calc->ray_dir_x < 0)
		*color = info->texture[1][TEX_HEIGHT * calc->tex_y + calc->tex_x];
	else if (calc->side == 0)
		*color = info->texture[0][TEX_HEIGHT * calc->tex_y + calc->tex_x];
	if (calc->side == 1 && calc->ray_dir_y < 0)
		*color = info->texture[3][TEX_HEIGHT * calc->tex_y + calc->tex_x];
	else if (calc->side == 1)
		*color = info->texture[2][TEX_HEIGHT * calc->tex_y + calc->tex_x];
}

void	draw_texture(t_info *info, t_calc *calc, int y)
{
	int	x;
	int	color;

	x = 0;
	color = 0;
	set_tex_elements(info, calc);
	x = calc->draw_start;
	while (x < calc->draw_end)
	{
		calc->tex_start += calc->step;
		calc->tex_y = (int)calc->tex_start;
		if (TEX_HEIGHT * calc->tex_y + calc->tex_x < 64 * 64 - 1)
		{
			get_texture_color(info, calc, &color);
		}
		info->buf[x][y] = color;
		x++;
	}
}

void	drawing(t_info *info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < info->win_height)
	{
		x = 0;
		while (x < info->win_width)
		{
			info->img.data[y * (info->img.size_l / 4) + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}
