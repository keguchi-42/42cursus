/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:49:35 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/07 21:44:12 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_linux.h"

void	set_sprite(t_info *info)
{
	int	i;

	i = 0;
	info->sprites = malloc(sizeof(t_sp) * (info->sprite_count));
	if (!(info->sprites))
		error_exit(MALLOC_ERROR);
	while (i < info->sprite_count)
	{
		info->sprites[i].x = 0;
		info->sprites[i].y = 0;
		info->sprites[i].sprite_dist = 0;
		i++;
	}
}

void	get_sprite_info(t_info *in)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (x < in->map.map_height)
	{
		y = 0;
		while (y < in->map.map_width)
		{
			if (in->map.worldmap[x][y] == '2')
			{
				in->sprites[i].x = (double)x + 0.5;
				in->sprites[i].y = (double)y + 0.5;
				in->sprites[i].sprite_dist = (in->pos_x - in->sprites[i].x)
					* (in->pos_x - in->sprites[i].x) + (in->pos_y
						- in->sprites[i].y) * (in->pos_y - in->sprites[i].y);
				i++;
			}
			y++;
		}
		x++;
	}
}

void	swap_elements(t_sp *sprites, int j)
{
	t_sp	swap;

	swap.x = 0;
	swap.y = 0;
	swap.sprite_dist = 0;
	swap.x = sprites[j].x;
	swap.y = sprites[j].y;
	swap.sprite_dist = sprites[j].sprite_dist;
	sprites[j].x = sprites[j + 1].x;
	sprites[j].y = sprites[j + 1].y;
	sprites[j].sprite_dist = sprites[j + 1].sprite_dist;
	sprites[j + 1].x = swap.x;
	sprites[j + 1].y = swap.y;
	sprites[j + 1].sprite_dist = swap.sprite_dist;
}

void	sort_sprite(t_sp *sprites, int sprite_count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sprite_count)
	{
		j = 0;
		while (j < sprite_count - 1)
		{
			if (sprites[j].sprite_dist < sprites[j + 1].sprite_dist)
				swap_elements(sprites, j);
			j++;
		}
		i++;
	}
}

void	calculate_sprite(t_info *info)
{
	get_sprite_info(info);
	sort_sprite(info->sprites, info->sprite_count);
	draw_sprite(info, info->sprites, &info->calc_sp);
	return ;
}
