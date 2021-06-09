/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:51:45 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/08 11:48:55 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_mac.h"

void	check_path_space(char *line, int i)
{
	ft_skipspace(line, &i);
	while (line[i] != '\0' && line[i] != ' ')
		i++;
	ft_skipspace(line, &i);
	if (line[i] != '\0')
		error_exit(TEXTURE_ERROR);
}

void	check_resolution(char *line, int i)
{
	ft_skipspace(line, &i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	ft_skipspace(line, &i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	ft_skipspace(line, &i);
	if (line[i] != '\0')
		error_exit(WIN_SIZE_ERROR);
}

void	gnl_error_check(t_info *info, int ret, int count, int line_num)
{
	info->map.map_width = count;
	info->map.map_height = line_num;
	if (ret == -1)
		error_exit(GNL_ERROR);
}
