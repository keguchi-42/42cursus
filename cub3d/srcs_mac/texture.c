/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 07:45:11 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/08 11:49:45 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_mac.h"

void	get_xpm_file(t_info *info, int *texture, char *path, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	img->img = mlx_xpm_file_to_image(info->mlx, path,
			&img->img_width, &img->img_height);
	if (img->img == (void *)0)
		error_exit(TEXTURE_ERROR);
	if (img->img_width != 64 || img->img_height != 64)
		error_exit(TEXTURE_ERROR);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_l, &img->endian);
	while (i < img->img_height)
	{
		j = 0;
		while (j < img->img_width)
		{
			texture[img->img_width * i + j] = img->data[img->img_width * i + j];
			j++;
		}
		i++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	get_xpm_file(info, info->texture[0], info->map.path_n, &img);
	get_xpm_file(info, info->texture[1], info->map.path_s, &img);
	get_xpm_file(info, info->texture[2], info->map.path_w, &img);
	get_xpm_file(info, info->texture[3], info->map.path_e, &img);
	get_xpm_file(info, info->texture[4], info->map.path_sprite, &img);
}

void	init_texture(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 5)
	{
		j = 0;
		while (j < TEX_HEIGHT * TEX_WIDTH)
		{
			info->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	set_texture(t_info *info)
{
	int	i;

	i = 0;
	info->texture = malloc(sizeof(int *) * (5 + 1));
	if (!(info->texture))
		error_exit(MALLOC_ERROR);
	info->texture[5] = NULL;
	while (i < 5)
	{
		info->texture[i] = malloc(sizeof(int) * TEX_HEIGHT * TEX_WIDTH);
		if (!(info->texture[i]))
			error_exit(MALLOC_ERROR);
		i++;
	}
	init_texture(info);
}
