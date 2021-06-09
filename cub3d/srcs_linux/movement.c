/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 07:31:23 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/07 21:44:39 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_linux.h"

void	key_move(t_info *info)
{
	if (info->key_w)
	{
		if (info->map.worldmap[(int)(info->pos_x
				+ info->dir_x * info->move_speed
				+ FLT_MIN * info->dir_num)][(int)(info->pos_y)] == '0')
			info->pos_x += info->dir_x * info->move_speed;
		if (info->map.worldmap[(int)(info->pos_x)]
				[(int)(info->pos_y + info->dir_y
				* info->move_speed + FLT_MIN * info->dir_num)] == '0')
			info->pos_y += info->dir_y * info->move_speed;
	}
	if (info->key_s)
	{
		if (info->map.worldmap[(int)(info->pos_x
				- info->dir_x * info->move_speed
				- FLT_MIN * info->dir_num)][(int)(info->pos_y)] == '0')
			info->pos_x -= info->dir_x * info->move_speed;
		if (info->map.worldmap[(int)(info->pos_x)]
				[(int)(info->pos_y - info->dir_y
				* info->move_speed - FLT_MIN * info->dir_num)] == '0')
			info->pos_y -= info->dir_y * info->move_speed;
	}
}

void	key_strafe(t_info *info)
{
	if (info->key_d)
	{
		if (info->map.worldmap[(int)(info->pos_x)]
				[(int)(info->pos_y - info->dir_x
				* info->move_speed - FLT_MIN * info->dir_num)] == '0')
			info->pos_y -= info->dir_x * info->move_speed;
		if (info->map.worldmap[(int)(info->pos_x
				+ info->dir_y * info->move_speed
				+ FLT_MIN * info->dir_num)][(int)(info->pos_y)] == '0')
			info->pos_x += info->dir_y * info->move_speed;
	}
	if (info->key_a)
	{
		if (info->map.worldmap[(int)(info->pos_x)]
				[(int)(info->pos_y + info->dir_x
				* info->move_speed + FLT_MIN * info->dir_num)] == '0')
			info->pos_y += info->dir_x * info->move_speed;
		if (info->map.worldmap[(int)(info->pos_x
				- info->dir_y * info->move_speed
				- FLT_MIN * info->dir_num)][(int)(info->pos_y)] == '0')
			info->pos_x -= info->dir_y * info->move_speed;
	}
}

void	key_rotate_r(t_info *info)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = 0;
	oldplane_x = 0;
	if (info->key_right)
	{
		olddir_x = info->dir_x;
		oldplane_x = info->plane_x;
		info->dir_x = info->dir_x * cos(-info->rot_speed)
			- info->dir_y * sin(-info->rot_speed);
		info->dir_y = olddir_x * sin(-info->rot_speed)
			+ info->dir_y * cos(-info->rot_speed);
		info->plane_x = info->plane_x * cos(-info->rot_speed)
			- info->plane_y * sin(-info->rot_speed);
		info->plane_y = oldplane_x * sin(-info->rot_speed)
			+ info->plane_y * cos(-info->rot_speed);
	}
}

void	key_rotate_l(t_info *info)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = 0;
	oldplane_x = 0;
	if (info->key_left)
	{
		olddir_x = info->dir_x;
		oldplane_x = info->plane_x;
		info->dir_x = info->dir_x * cos(info->rot_speed)
			- info->dir_y * sin(info->rot_speed);
		info->dir_y = olddir_x * sin(info->rot_speed)
			+ info->dir_y * cos(info->rot_speed);
		info->plane_x = info->plane_x * cos(info->rot_speed)
			- info->plane_y * sin(info->rot_speed);
		info->plane_y = oldplane_x * sin(info->rot_speed)
			+ info->plane_y * cos(info->rot_speed);
	}
}

void	key_update(t_info *info)
{
	key_move(info);
	key_strafe(info);
	key_rotate_r(info);
	key_rotate_l(info);
	if (info->key_esc)
		exit_game(info);
}
