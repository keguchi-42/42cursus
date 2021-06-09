/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 06:50:42 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/07 21:44:26 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_linux.h"

void	set_sprite_elements2(t_info *info, t_sp *sp, t_calc_sp *csp, int i)
{
	csp->sprite_x = sp[i].x - info->pos_x;
	csp->sprite_y = sp[i].y - info->pos_y;
	csp->inv_det = 1.0 / (info->plane_x * info->dir_y
			- info->dir_x * info->plane_y);
	csp->new_x = csp->inv_det * (info->dir_y * csp->sprite_x
			- info->dir_x * csp->sprite_y);
	csp->new_y = csp->inv_det * (-info->plane_y * csp->sprite_x
			+ info->plane_x * csp->sprite_y);
	csp->sprite_screen_x = (int)((info->win_width / 2)
			* (1 + csp->new_x / csp->new_y));
	csp->sprite_height = (int)fabs(info->win_height / csp->new_y);
	csp->draw_start_y = -csp->sprite_height / 2
		+ info->win_height / 2;
}

void	set_sprite_elements1(t_info *info, t_sp *sp, t_calc_sp *csp, int i)
{
	set_sprite_elements2(info, sp, csp, i);
	if (csp->draw_start_y < 0)
		csp->draw_start_y = 0;
	csp->draw_end_y = csp->sprite_height / 2
		+ info->win_height / 2;
	if (csp->draw_end_y >= info->win_height)
		csp->draw_end_y = info->win_height;
	csp->sprite_width = (int)fabs(info->win_width / csp->new_y);
	csp->draw_start_x = -csp->sprite_width / 2 + csp->sprite_screen_x;
	if (csp->draw_start_x < 0)
		csp->draw_start_x = 0;
	csp->draw_end_x = csp->sprite_width / 2 + csp->sprite_screen_x;
	if (csp->draw_end_x >= info->win_width)
		csp->draw_end_x = info->win_width;
}

void	set_tex_elements(t_info *info, t_calc *calc)
{
	calc->draw_height = (int)(info->win_height / calc->wall_dist);
	calc->draw_start = info->win_height / 2 - calc->draw_height / 2;
	if (calc->draw_start < 0)
		calc->draw_start = 0;
	calc->draw_end = info->win_height / 2 + calc->draw_height / 2;
	if (calc->draw_end > info->win_height)
		calc->draw_end = info->win_height;
	if (calc->side == 0)
		calc->wall_x = info->pos_y + calc->wall_dist * calc->ray_dir_y;
	else
		calc->wall_x = info->pos_x + calc->wall_dist * calc->ray_dir_x;
	calc->wall_x -= floor(calc->wall_x);
	calc->tex_x = (int)(calc->wall_x * (double)TEX_WIDTH);
	if (calc->side == 0 && calc->ray_dir_x > 0)
		calc->tex_x = TEX_WIDTH - calc->tex_x - 1;
	if (calc->side == 1 && calc->ray_dir_y < 0)
		calc->tex_x = TEX_WIDTH - calc->tex_x - 1;
	calc->step = 1.0 * TEX_HEIGHT / calc->draw_height;
	calc->tex_start = (calc->draw_start - info->win_height / 2
			+ calc->draw_height / 2) * calc->step;
}
