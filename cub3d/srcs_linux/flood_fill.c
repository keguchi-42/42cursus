/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 07:57:59 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/07 21:45:26 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_linux.h"

void	flood_fill(t_info *info, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= info->map.map_height
		|| y >= info->map.map_width || map[x][y] == ' ')
	{
		ft_free_free((void **)map);
		error_exit(FLOOD_FILL_ERROR);
	}
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	if (map[x][y] == '0' || map[x][y] == '2')
		map[x][y] = 'X';
	flood_fill(info, map, x + 1, y);
	flood_fill(info, map, x, y + 1);
	flood_fill(info, map, x - 1, y);
	flood_fill(info, map, x, y - 1);
}

void	map_closed(t_info *info)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char *) * (info->map.map_height + 1));
	if (!(tmp))
		error_exit(MALLOC_ERROR);
	while (i < info->map.map_height)
	{
		tmp[i] = ft_strdup(info->map.worldmap[i]);
		i++;
	}
	tmp[i] = NULL;
	flood_fill(info, tmp, (int)info->pos_x, (int)info->pos_y);
	ft_free_free((void **)tmp);
}
