/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:48:56 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/05 02:59:26 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_mac.h"

void	calc_rgb(t_info *info)
{
	info->map.f_color = (info->map.f_red * (int)pow(16, 4))
		+ (info->map.f_green * (int)pow(16, 2)) + info->map.f_blue;
	info->map.c_color = (info->map.c_red * (int)pow(16, 4))
		+ (info->map.c_green * (int)pow(16, 2)) + info->map.c_blue;
}

void	get_calc_data(t_info *info, t_calc *calc, int y)
{
	calc->camera_x = 2 * y / (double)info->win_width - 1;
	calc->ray_dir_x = info->dir_x + info->plane_x * calc->camera_x;
	calc->ray_dir_y = info->dir_y + info->plane_y * calc->camera_x;
	calc->map_x = (int)info->pos_x;
	calc->map_y = (int)info->pos_y;
	calc->delta_dist_x = fabs(1 / calc->ray_dir_x);
	calc->delta_dist_y = fabs(1 / calc->ray_dir_y);
}

void	get_sidedist(t_info *info, t_calc *calc, int y)
{
	get_calc_data(info, calc, y);
	if (calc->ray_dir_x < 0)
	{
		calc->step_x = -1;
		calc->side_dist_x = (info->pos_x - calc->map_x) * calc->delta_dist_x;
	}
	else
	{
		calc->step_x = 1;
		calc->side_dist_x = (calc->map_x + 1.0
				- info->pos_x) * calc->delta_dist_x;
	}
	if (calc->ray_dir_y < 0)
	{
		calc->step_y = -1;
		calc->side_dist_y = (info->pos_y - calc->map_y) * calc->delta_dist_y;
	}
	else
	{
		calc->step_y = 1;
		calc->side_dist_y = (calc->map_y + 1.0
				- info->pos_y) * calc->delta_dist_y;
	}
}

void	wall_hit(t_info *info, t_calc *calc)
{
	while (calc->hit == 0)
	{
		if (calc->side_dist_x < calc->side_dist_y)
		{
			calc->side_dist_x += calc->delta_dist_x;
			calc->map_x += calc->step_x;
			calc->side = 0;
		}
		else
		{
			calc->side_dist_y += calc->delta_dist_y;
			calc->map_y += calc->step_y;
			calc->side = 1;
		}
		if (info->map.worldmap[calc->map_x][calc->map_y] == '1')
			calc->hit = 1;
	}
	if (calc->side == 0)
		calc->wall_dist = (calc->map_x - info->pos_x
				+ (1 - calc->step_x) / 2) / calc->ray_dir_x;
	else
		calc->wall_dist = (calc->map_y - info->pos_y
				+ (1 - calc->step_y) / 2) / calc->ray_dir_y;
}

void	calculate_wall(t_info *info, t_calc *calc)
{
	int	y;

	y = 0;
	draw_background(info);
	while (y < info->win_width)
	{
		initialize_calc(calc);
		get_sidedist(info, &info->calc, y);
		wall_hit(info, &info->calc);
		draw_texture(info, &info->calc, y);
		info->z_buffer[y] = calc->wall_dist;
		y++;
	}
}
