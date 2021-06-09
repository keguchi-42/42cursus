/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 04:24:54 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/08 11:41:01 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_mac.h"

void	get_window_size_else(t_info *info, char *line, int i, int ret)
{
	int	max_width;
	int	max_height;

	init_max(info, &max_width, &max_height);
	if (ret == -1)
	{
		ft_skipspace(line, &i);
		while (line[i] != '\0' && line[i] >= '0' && line[i] <= '9')
			i++;
		info->win_height = ft_atoi(line, &i);
		if (info->win_height < 1)
			error_exit(WIN_SIZE_ERROR);
		if (info->win_height > max_height)
			info->win_height = max_height;
	}
	if (ret == -2)
	{
		ft_skipspace(line, &i);
		info->win_width = ft_atoi(line, &i);
		if (info->win_width < 1)
			error_exit(WIN_SIZE_ERROR);
		if (info->win_width > max_width)
			info->win_width = max_width;
	}
}

void	get_window_size(t_info *info, char *line, int i)
{
	int	max_width;
	int	max_height;
	int	ret;

	ret = 0;
	init_max(info, &max_width, &max_height);
	check_resolution(line, i);
	ret = check_int_max(info, line, i);
	if (ret == 0)
	{
		ft_skipspace(line, &i);
		info->win_width = ft_atoi(line, &i);
		if (info->win_width < 1)
			error_exit(WIN_SIZE_ERROR);
		if (info->win_width > max_width)
			info->win_width = max_width;
		info->win_height = ft_atoi(line, &i);
		if (info->win_height < 1)
			error_exit(WIN_SIZE_ERROR);
		if (info->win_height > max_height)
			info->win_height = max_height;
	}
	else
		get_window_size_else(info, line, i, ret);
	info->map.r_flag++;
}

void	get_texture_path(t_info *info, char *line, char c, int i)
{
	if (c == 'N')
	{
		info->map.path_n = ft_strdup_path(line, i);
		info->map.n_flag++;
	}
	else if (c == 'S')
	{
		info->map.path_s = ft_strdup_path(line, i);
		info->map.s_flag++;
	}
	else if (c == 'W')
	{
		info->map.path_w = ft_strdup_path(line, i);
		info->map.w_flag++;
	}
	else if (c == 'E')
	{
		info->map.path_e = ft_strdup_path(line, i);
		info->map.e_flag++;
	}
	else if (c == 'P')
	{
		info->map.path_sprite = ft_strdup_path(line, i);
		info->map.p_flag++;
	}
}

void	get_background_ccolor(t_info *info, char *line, int i)
{
	info->map.c_red = ft_atoi(line, &i);
	if (line[i] != ',' || line[i + 1] < '0' || line[i + 1] > '9')
		error_exit(CCOLOR_ERROR);
	i++;
	info->map.c_green = ft_atoi(line, &i);
	if (line[i] != ',' || line[i + 1] < '0' || line[i + 1] > '9')
		error_exit(CCOLOR_ERROR);
	i++;
	info->map.c_blue = ft_atoi(line, &i);
	ft_skipspace(line, &i);
	if (line[i])
		error_exit(CCOLOR_ERROR);
	info->map.c_flag++;
}

void	get_background_fcolor(t_info *info, char *line, int i)
{
	info->map.f_red = ft_atoi(line, &i);
	if (line[i] != ',' || line[i + 1] < '0' || line[i + 1] > '9')
		error_exit(FCOLOR_ERROR);
	i++;
	info->map.f_green = ft_atoi(line, &i);
	if (line[i] != ',' || line[i + 1] < '0' || line[i + 1] > '9')
		error_exit(FCOLOR_ERROR);
	i++;
	info->map.f_blue = ft_atoi(line, &i);
	ft_skipspace(line, &i);
	if (line[i])
		error_exit(FCOLOR_ERROR);
	info->map.f_flag++;
}
