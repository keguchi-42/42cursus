/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 06:23:17 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/08 11:34:15 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_linux.h"

void	set_position(t_info *info, int i)
{
	info->pos_x = info->map.map_num + 0.5;
	info->pos_y = i + 0.5;
}

void	respawn_dir2(t_info *info, char c)
{
	if (c == 'W')
	{
		info->dir_x = 0.0;
		info->dir_y = -1.0;
		info->plane_x = -FOV * 0.01;
		info->plane_y = 0.0;
		info->dir_num = -1;
	}
	else if (c == 'E')
	{
		info->dir_x = 0.0;
		info->dir_y = 1.0;
		info->plane_x = FOV * 0.01;
		info->plane_y = 0.0;
		info->dir_num = 1;
	}
}

void	respawn_dir(t_info *info, char c, int i)
{
	if (info->player_exist == 1)
		error_exit(FORMAT_ERROR);
	set_position(info, i);
	info->player_exist = 1;
	if (c == 'N')
	{
		info->dir_x = -1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = FOV * 0.01;
		info->dir_num = -1;
	}
	else if (c == 'S')
	{
		info->dir_x = 1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = -FOV * 0.01;
		info->dir_num = 1;
	}
	respawn_dir2(info, c);
}

void	get_worldmap2(t_info *info, char *line, char *tmp)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
			respawn_dir(info, line[i], i);
		tmp[i] = '0';
		if (line[i] == '1' || line[i] == '2' || line[i] == ' ')
			tmp[i] = line[i];
		if (line[i] == '2')
			info->sprite_count++;
		i++;
	}
	while (i < info->map.map_width)
	{
		tmp[i] = '0';
		i++;
	}
	tmp[i] = '\0';
}

void	get_worldmap(t_info *info, char *line)
{
	char	*tmp;

	if (check_new_line(info, line))
		return ;
	info->map.map_start = 1;
	if (this_is_worldmap(line) == -1)
		error_exit(FORMAT_ERROR);
	check_all_input(&info->map);
	tmp = malloc(sizeof(char) * (info->map.map_width + 1));
	if (!(tmp))
		error_exit(MALLOC_ERROR);
	get_worldmap2(info, line, tmp);
	info->map.worldmap[info->map.map_num] = ft_strdup(tmp);
	info->map.map_num++;
	ft_free((void *)tmp);
}
