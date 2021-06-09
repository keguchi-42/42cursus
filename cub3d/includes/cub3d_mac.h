/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_mac.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 01:30:12 by keguchi           #+#    #+#             */
/*   Updated: 2021/05/08 16:35:06 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MAC_H
# define CUB3D_MAC_H

# include "../mlx_mac/mlx.h"
# include "get_next_line.h"
# include "key_macos.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define FLT_MIN				0.000001
# define INT_MAX_COUNT			10

# define MAP_WIDTH_MAX			50
# define MAP_HEIGHT_MAX			50

# define TEX_WIDTH				64
# define TEX_HEIGHT				64
# define FOV					70

# define ARG_ERROR				1
# define FILE_NAME_ERROR		2
# define OPEN_ERROR				3
# define READ_ERROR				4
# define FCOLOR_ERROR			5
# define CCOLOR_ERROR			6
# define FORMAT_ERROR			7
# define MALLOC_ERROR			8
# define PLAYER_ERROR			9
# define FLOOD_FILL_ERROR		10
# define TEXTURE_ERROR			11
# define WIN_SIZE_ERROR			12
# define MAP_SIZE_ERROR			13
# define GNL_ERROR				14

# define TEST_ERROR				99

typedef struct s_sp
{
	double	x;
	double	y;
	double	sprite_dist;
}				t_sp;

typedef struct s_map
{
	char	*name;
	char	*path_n;
	char	*path_s;
	char	*path_w;
	char	*path_e;
	char	*path_sprite;
	int		f_red;
	int		f_blue;
	int		f_green;
	int		f_color;
	int		c_red;
	int		c_blue;
	int		c_green;
	int		c_color;
	char	**worldmap;
	int		r_flag;
	int		n_flag;
	int		s_flag;
	int		w_flag;
	int		e_flag;
	int		p_flag;
	int		f_flag;
	int		c_flag;
	int		map_width;
	int		map_height;
	int		map_start;
	int		map_num;
	int		map_end;
}				t_map;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_calc_sp
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	new_x;
	double	new_y;
	int		sprite_screen_x;
	int		sprite_height;
	int		sprite_width;
	int		draw_start_x;
	int		draw_start_y;
	int		draw_end_x;
	int		draw_end_y;
	int		tex_x;
	int		tex_y;
}				t_calc_sp;

typedef struct s_calc
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		draw_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_start;
}				t_calc;

typedef struct s_info
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	void		*mlx;
	void		*win;
	t_img		img;
	int			win_width;
	int			win_height;
	int			**buf;
	int			**texture;
	double		move_speed;
	double		rot_speed;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_esc;
	int			key_right;
	int			key_left;
	t_map		map;
	int			player_exist;
	int			dir_num;
	t_calc		calc;
	double		*z_buffer;
	t_sp		*sprites;
	t_calc_sp	calc_sp;
	int			sprite_count;
	int			save_flag;
}				t_info;

void	get_window_size_bmp(t_info *info, char *line, int i);
void	get_window_size_bmp_else(t_info *info, char *line, int i, int ret);
int		bmp_size_check(t_info *info, char *line, int i);

void	set_sprite(t_info *info);
void	get_sprite_info(t_info *info);
void	swap_elements(t_sp *sprites, int j);
void	sort_sprite(t_sp *sprites, int sprite_count);
void	calculate_sprite(t_info *in);

void	calc_rgb(t_info *info);
void	get_calc_data(t_info *info, t_calc *calc, int y);
void	get_sidedist(t_info *info, t_calc *calc, int y);
void	wall_hit(t_info *info, t_calc *calc);
void	calculate_wall(t_info *info, t_calc *calc);

void	ft_putstr_fd(char *str, int fd);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *line, int *i);
void	skip_num(char *line, int *i, int *count);
void	ft_skipspace(char *line, int *i);

int		exit_game(t_info *info);
int		game_loop(t_info *info);
void	init_game(t_info *info, char *map_name);
void	cub3d(t_info *info);
int		main(int argc, char **argv);

void	draw_half_window(t_info *info, int x, int y, int win);
void	drawing_sprite(t_info *info, t_calc_sp *calc_sp, int x, int y);

void	draw_sprite(t_info *info, t_sp *sprites, t_calc_sp *calc_sp);
void	draw_background(t_info *info);
void	draw_texture(t_info *info, t_calc *calc, int y);
void	drawing(t_info *info);

int		check_int_max(t_info *info, char *line, int i);
void	rgb_check(t_info *info);
void	check_file_name(char *name);
void	check_all_input(t_map *map);
int		check_new_line(t_info *info, char *line);

void	check_path_space(char *line, int i);
void	check_resolution(char *line, int i);
void	gnl_error_check(t_info *info, int ret, int count, int line_num);

void	error_exit(int error_num);
void	error_exit2(int error_num);

void	flood_fill(t_info *info, char **map, int x, int y);
void	map_closed(t_info *info);

void	ft_free(void *ptr);
void	ft_free_free(void **ptr);
void	all_free(t_info *info);

void	get_map_size(t_info *info);
void	get_map_size_gnl(t_info *info, char *line, int fd);
void	parse_info(t_info *info, char *line);
void	open_file(t_info *info);
void	get_cubfile(t_info *info);

int		this_is_worldmap(char *line);
int		ft_strlen_path(const char *s);
char	*ft_strdup_path(char *line, int num);

void	set_position(t_info *info, int i);
void	respawn_dir(t_info *info, char c, int i);
void	respawn_dir2(t_info *info, char c);
void	get_worldmap(t_info *info, char *line);
void	get_worldmap2(t_info *info, char *line, char *tmp);

void	set_initial_value(t_info *info);
void	init_buf(t_info *info);
void	init_zbuf(t_info *info);
void	initialize_calc_sp(t_calc_sp *calc_sp);
void	initialize_calc(t_calc *calc);
void	initialize_info(t_info *info);
void	init_max(t_info *info, int *max_width, int *max_height);

void	make_file_header(t_info *info, int fd);
void	make_info_header(t_info *info, int fd);
void	make_image_data(t_info *info, int fd);
int		make_bmp(t_info *info);

void	key_move(t_info *info);
void	key_strafe(t_info *info);
void	key_rotate_r(t_info *info);
void	key_rotate_l(t_info *info);
void	key_update(t_info *info);

int		key_press(int key, t_info *info);
int		key_release(int key, t_info *info);

void	get_window_size(t_info *info, char *line, int i);
void	get_window_size_else(t_info *info, char *line, int i, int ret);
void	get_texture_path(t_info *info, char *line, char c, int i);
void	get_background_ccolor(t_info *info, char *line, int i);
void	get_background_fcolor(t_info *info, char *line, int i);

void	set_sprite_elements1(t_info *info, t_sp *sp, t_calc_sp *csp, int i);
void	set_sprite_elements2(t_info *info, t_sp *sp, t_calc_sp *csp, int i);
void	set_tex_elements(t_info *info, t_calc *calc);

void	get_xpm_file(t_info *info, int *texture, char *path, t_img *img);
void	load_texture(t_info *info);
void	init_texture(t_info *info);
void	set_texture(t_info *info);

#endif
