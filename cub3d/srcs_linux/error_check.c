/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 07:48:45 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/12 16:09:13 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_linux.h"

int	check_int_max(t_info *info, char *line, int i)
{
	int	count;
	int	ret;
	int	max_width;
	int	max_height;

	count = 0;
	ret = 0;
	init_max(info, &max_width, &max_height);
	skip_num(line, &i, &count);
	if (count >= INT_MAX_COUNT)
	{
		info->win_width = max_width;
		ret -= 1;
	}
	count = 0;
	skip_num(line, &i, &count);
	if (count >= INT_MAX_COUNT)
	{
		info->win_height = max_height;
		ret -= 2;
	}
	return (ret);
}

void	rgb_check(t_info *info)
{
	if (info->map.f_red > 255 || info->map.f_red < 0)
		error_exit(FCOLOR_ERROR);
	if (info->map.f_green > 255 || info->map.f_green < 0)
		error_exit(FCOLOR_ERROR);
	if (info->map.f_blue > 255 || info->map.f_blue < 0)
		error_exit(FCOLOR_ERROR);
	if (info->map.c_red > 255 || info->map.c_red < 0)
		error_exit(CCOLOR_ERROR);
	if (info->map.c_green > 255 || info->map.c_green < 0)
		error_exit(CCOLOR_ERROR);
	if (info->map.c_blue > 255 || info->map.c_blue < 0)
		error_exit(CCOLOR_ERROR);
}

void	check_file_name(char *name)
{
	char	extension[5];
	int		i;

	i = 0;
	while (name[i])
		i++;
	extension[0] = name[i - 4];
	extension[1] = name[i - 3];
	extension[2] = name[i - 2];
	extension[3] = name[i - 1];
	extension[4] = name[i];
	if (ft_strcmp(extension, ".cub") != 0)
		error_exit(FILE_NAME_ERROR);
	return ;
}

void	check_all_input(t_map *map)
{
	if ((map->r_flag + map->n_flag + map->s_flag + map->w_flag + map->e_flag
			+ map->p_flag + map->f_flag + map->c_flag) != 8)
		error_exit(FORMAT_ERROR);
}

int	check_new_line(t_info *info, char *line)
{
	int	len;

	len = 0;
	len = ft_strlen(line);
	if (len == 0 && info->map.map_start == 0)
		return (1);
	else if (len == 0 && info->map.map_start == 1)
	{
		info->map.map_end = 1;
		return (1);
	}
	else if (len > 0 && info->map.map_end == 1)
		error_exit(FORMAT_ERROR);
	return (0);
}
