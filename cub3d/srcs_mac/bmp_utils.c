/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 13:43:01 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/08 16:35:35 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_mac.h"

int	bmp_size_check(t_info *info, char *line, int i)
{
	int	count;
	int	ret;

	count = 0;
	ret = 0;
	skip_num(line, &i, &count);
	if (count >= 5)
	{
		info->win_width = 3000;
		ret -= 1;
	}
	count = 0;
	skip_num(line, &i, &count);
	if (count >= 5)
	{
		info->win_height = 3000;
		ret -= 2;
	}
	return (ret);
}

void	get_window_size_bmp_else(t_info *info, char *line, int i, int ret)
{
	if (ret == -1)
	{
		ft_skipspace(line, &i);
		while (line[i] != '\0' && line[i] >= '0' && line[i] <= '9')
			i++;
		info->win_height = ft_atoi(line, &i);
		if (info->win_height < 1)
			error_exit(WIN_SIZE_ERROR);
		if (info->win_height > 3000)
			info->win_height = 3000;
	}
	if (ret == -2)
	{
		ft_skipspace(line, &i);
		info->win_width = ft_atoi(line, &i);
		if (info->win_width < 1)
			error_exit(WIN_SIZE_ERROR);
		if (info->win_width > 3000)
			info->win_width = 3000;
	}
}

void	get_window_size_bmp(t_info *info, char *line, int i)
{
	int	ret;

	ret = 0;
	check_resolution(line, i);
	ret = bmp_size_check(info, line, i);
	if (ret == 0)
	{
		ft_skipspace(line, &i);
		info->win_width = ft_atoi(line, &i);
		if (info->win_width < 1)
			error_exit(WIN_SIZE_ERROR);
		if (info->win_width > 3000)
			info->win_width = 3000;
		info->win_height = ft_atoi(line, &i);
		if (info->win_height < 1)
			error_exit(WIN_SIZE_ERROR);
		if (info->win_height > 3000)
			info->win_height = 3000;
	}
	else
		get_window_size_bmp_else(info, line, i, ret);
	info->map.r_flag++;
}
