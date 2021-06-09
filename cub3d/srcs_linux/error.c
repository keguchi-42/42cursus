/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 07:35:32 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/07 21:45:32 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_linux.h"

void	error_exit2(int error_num)
{
	if (error_num == FORMAT_ERROR)
		ft_putstr_fd("file format error\n", 2);
	else if (error_num == MALLOC_ERROR)
		ft_putstr_fd("malloc error\n", 2);
	else if (error_num == PLAYER_ERROR)
		ft_putstr_fd("player not found\n", 2);
	else if (error_num == FLOOD_FILL_ERROR)
		ft_putstr_fd("map is not surrounded by wall\n", 2);
	else if (error_num == TEXTURE_ERROR)
		ft_putstr_fd("texture error\n", 2);
	else if (error_num == WIN_SIZE_ERROR)
		ft_putstr_fd("window size error\n", 2);
	else if (error_num == MAP_SIZE_ERROR)
		ft_putstr_fd("map is too large\n", 2);
	else if (error_num == GNL_ERROR)
		ft_putstr_fd("file reading error\n", 2);
	else if (error_num == TEST_ERROR)
		ft_putstr_fd("GOTHA!\n", 2);
}

void	error_exit(int error_num)
{
	ft_putstr_fd("Error\n", 2);
	if (error_num == ARG_ERROR)
		ft_putstr_fd("Arguments error\n", 2);
	else if (error_num == FILE_NAME_ERROR)
		ft_putstr_fd("File name error\n", 2);
	else if (error_num == OPEN_ERROR)
		ft_putstr_fd("Open error\n", 2);
	else if (error_num == READ_ERROR)
		ft_putstr_fd("Read error\n", 2);
	else if (error_num == FCOLOR_ERROR)
		ft_putstr_fd("Floor color error\n", 2);
	else if (error_num == CCOLOR_ERROR)
		ft_putstr_fd("Ceilling color error\n", 2);
	error_exit2(error_num);
	exit(1);
}
