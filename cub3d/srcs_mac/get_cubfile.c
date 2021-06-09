/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cubfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 06:23:02 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/08 14:08:15 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_mac.h"

void	get_map_size_gnl(t_info *info, char *line, int fd)
{
	int	ret;
	int	line_num;
	int	count;

	ret = 0;
	line_num = 0;
	count = 0;
	ret = get_next_line(fd, &line);
	while (ret != -1)
	{
		if (ret == 0 && !(*line))
			break ;
		if (this_is_worldmap(line) == 0)
		{
			line_num++;
			if (count < ft_strlen(line))
				count = ft_strlen(line);
		}
		free(line);
		ret = get_next_line(fd, &line);
	}
	gnl_error_check(info, ret, count, line_num);
	free(line);
}

void	get_map_size(t_info *info)
{
	int		fd;
	char	*line;

	fd = 0;
	line = NULL;
	fd = open(info->map.name, O_RDONLY);
	if (fd < 0)
		error_exit(OPEN_ERROR);
	get_map_size_gnl(info, line, fd);
	close(fd);
	if (info->map.map_width > MAP_WIDTH_MAX
		|| info->map.map_height > MAP_HEIGHT_MAX)
		error_exit(MAP_SIZE_ERROR);
}

void	parse_info(t_info *info, char *line)
{
	int		i;

	i = 0;
	ft_skipspace(line, &i);
	if (line[i] == 'R' && line[i + 1] == ' ' && info->save_flag == 0)
		get_window_size(info, line, i + 2);
	else if (line[i] == 'R' && line[i + 1] == ' ' && info->save_flag == 1)
		get_window_size_bmp(info, line, i + 2);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		get_texture_path(info, line, 'N', i + 3);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		get_texture_path(info, line, 'S', i + 3);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		get_texture_path(info, line, 'W', i + 3);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		get_texture_path(info, line, 'E', i + 3);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		get_texture_path(info, line, 'P', i + 2);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		get_background_fcolor(info, line, i + 2);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		get_background_ccolor(info, line, i + 2);
	else
		get_worldmap(info, line);
}

void	open_file(t_info *info)
{
	int		fd;
	char	*line;
	int		ret;

	fd = 0;
	ret = 0;
	fd = open(info->map.name, O_RDONLY);
	if (fd < 0)
		error_exit(OPEN_ERROR);
	ret = get_next_line(fd, &line);
	while (ret != -1)
	{
		if (ret == 0 && !(*line))
		{
			free(line);
			return ;
		}
		parse_info(info, line);
		free(line);
		ret = get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	if (ret == -1)
		error_exit(GNL_ERROR);
}

void	get_cubfile(t_info *info)
{
	check_file_name(info->map.name);
	get_map_size(info);
	info->map.worldmap = malloc(sizeof(char *) * (info->map.map_height + 1));
	if (!(info->map.worldmap))
		error_exit(MALLOC_ERROR);
	info->map.worldmap[info->map.map_height] = NULL;
	open_file(info);
	init_buf(info);
	init_zbuf(info);
	if (info->player_exist == 0)
		error_exit(PLAYER_ERROR);
	map_closed(info);
	rgb_check(info);
}
