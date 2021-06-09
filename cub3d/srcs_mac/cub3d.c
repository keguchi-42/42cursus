/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:00:08 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/08 14:01:34 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_mac.h"

int	exit_game(t_info *info)
{
	all_free(info);
	exit(0);
	return (0);
}

int	game_loop(t_info *info)
{
	calculate_wall(info, &info->calc);
	calculate_sprite(info);
	drawing(info);
	key_update(info);
	return (0);
}

void	init_game(t_info *info, char *map_name)
{
	info->mlx = mlx_init();
	initialize_calc(&info->calc);
	initialize_calc_sp(&info->calc_sp);
	set_initial_value(info);
	info->map.name = ft_strdup(map_name);
	get_cubfile(info);
	set_texture(info);
	load_texture(info);
	set_sprite(info);
}

void	cub3d(t_info *info)
{
	info->win = mlx_new_window(info->mlx, info->win_width,
			info->win_height, "cub3D");
	info->img.img = mlx_new_image(info->mlx, info->win_width, info->win_height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
			&info->img.bpp, &info->img.size_l, &info->img.endian);
	mlx_loop_hook(info->mlx, &game_loop, info);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_RELEASE, 1, key_release, info);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, exit_game, info);
	mlx_loop(info->mlx);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 2 || (argc == 3 && ft_strcmp(argv[2], "--save") == 0))
	{
		initialize_info(&info);
		if (argc == 3)
		{
			info.save_flag = 1;
			init_game(&info, argv[1]);
			make_bmp(&info);
		}
		init_game(&info, argv[1]);
		cub3d(&info);
	}
	else
		error_exit(ARG_ERROR);
	return (0);
}
