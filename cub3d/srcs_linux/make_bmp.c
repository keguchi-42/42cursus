/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 02:55:29 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/07 21:44:44 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_linux.h"

void	make_file_header(t_info *info, int fd)
{
	unsigned int	file_size;
	unsigned int	image_offset;

	file_size = 0;
	image_offset = 0;
	file_size = 14 + 40 + info->win_width * info->win_height * 4;
	image_offset = 14 + 40;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0", 2);
	write(fd, "\0\0", 2);
	write(fd, &image_offset, 4);
}

void	make_info_header(t_info *info, int fd)
{
	unsigned int	header_size;
	unsigned int	plane;
	unsigned int	bit_num;
	unsigned int	image_size;

	header_size = 0;
	plane = 0;
	bit_num = 0;
	image_size = 0;
	header_size = 40;
	plane = 1;
	bit_num = 32;
	image_size = info->win_width * info->win_height * 4;
	write(fd, &header_size, 4);
	write(fd, &info->win_width, 4);
	write(fd, &info->win_height, 4);
	write(fd, &plane, 2);
	write(fd, &bit_num, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &image_size, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

void	make_image_data(t_info *info, int fd)
{
	unsigned int	image_data;
	int				x;
	int				y;

	image_data = 0;
	x = 0;
	y = 0;
	x = info->win_height - 1;
	while (x >= 0)
	{
		y = 0;
		while (y < info->win_width)
		{
			image_data = info->buf[x][y];
			write(fd, &image_data, 4);
			y++;
		}
		x--;
	}
}

int	make_bmp(t_info *info)
{
	int	fd;

	fd = 0;
	calculate_wall(info, &info->calc);
	calculate_sprite(info);
	fd = open("save.bmp", O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);
	if (fd < 0)
		error_exit(OPEN_ERROR);
	make_file_header(info, fd);
	make_info_header(info, fd);
	make_image_data(info, fd);
	close(fd);
	exit_game(info);
	return (0);
}
