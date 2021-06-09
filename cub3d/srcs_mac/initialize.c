/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 07:30:44 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/08 13:59:04 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_mac.h"

void	set_initial_value(t_info *info)
{
	info->win_width = 0;
	info->win_height = 0;
	info->move_speed = 0.05;
	info->rot_speed = 0.05;
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_esc = 0;
	info->key_left = 0;
	info->key_right = 0;
	info->player_exist = 0;
	info->dir_num = 0;
}

void	initialize_calc_sp(t_calc_sp *calc_sp)
{
	calc_sp->sprite_x = 0;
	calc_sp->sprite_y = 0;
	calc_sp->inv_det = 0;
	calc_sp->new_x = 0;
	calc_sp->new_y = 0;
	calc_sp->sprite_screen_x = 0;
	calc_sp->sprite_height = 0;
	calc_sp->sprite_width = 0;
	calc_sp->draw_start_x = 0;
	calc_sp->draw_start_y = 0;
	calc_sp->draw_end_x = 0;
	calc_sp->draw_end_y = 0;
	calc_sp->tex_x = 0;
	calc_sp->tex_y = 0;
}

void	initialize_calc(t_calc *calc)
{
	calc->camera_x = 0;
	calc->ray_dir_x = 0;
	calc->ray_dir_y = 0;
	calc->map_x = 0;
	calc->map_y = 0;
	calc->side_dist_x = 0;
	calc->side_dist_y = 0;
	calc->delta_dist_x = 0;
	calc->delta_dist_y = 0;
	calc->wall_dist = 0;
	calc->step_x = 0;
	calc->step_y = 0;
	calc->hit = 0;
	calc->side = 0;
	calc->draw_height = 0;
	calc->draw_start = 0;
	calc->draw_end = 0;
	calc->wall_x = 0;
	calc->tex_x = 0;
	calc->tex_y = 0;
	calc->step = 0;
	calc->tex_start = 0;
}

void	initialize_info(t_info *info)
{
	info->map.f_red = 0;
	info->map.f_blue = 0;
	info->map.f_green = 0;
	info->map.f_color = 0;
	info->map.c_red = 0;
	info->map.c_blue = 0;
	info->map.c_green = 0;
	info->map.c_color = 0;
	info->map.r_flag = 0;
	info->map.n_flag = 0;
	info->map.s_flag = 0;
	info->map.w_flag = 0;
	info->map.e_flag = 0;
	info->map.p_flag = 0;
	info->map.f_flag = 0;
	info->map.c_flag = 0;
	info->map.map_width = 0;
	info->map.map_height = 0;
	info->map.map_start = 0;
	info->map.map_num = 0;
	info->map.map_end = 0;
	info->sprite_count = 0;
	info->save_flag = 0;
}
