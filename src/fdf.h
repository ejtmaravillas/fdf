/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:06:04 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/13 19:43:29 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../mlx/mlx.h"
// # include <X11/X.h>
// # include <X11/keysym.h>

# define WINDOW_WIDTH 1400
# define WINDOW_HEIGHT 768

typedef struct s_map_point
{
	float	x;
	float	y;
	float	z;
}	t_map_point;

typedef struct s_color_point
{
	int	r;
	int	g;
	int	b;
	int	t;
}	t_color_point;

typedef struct s_map_data
{
	int			**data_map;
	char		***color_map;
	t_color_point **color_point;
	char		*name;
	int			row;
	int			col;
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map_point	**point_map;
	float		theta_x;
	float		theta_y;
	float		theta_z;
	int			projection;
	float		p_anglex;
	float		p_angley;
	float		max_x;
	float		max_y;
	float		max_z;
	float		min_x;
	float		min_y;
	float		min_z;
	float		x_offset;
	float		y_offset;
	float		z_factor;
	float		initx_offset;
	float		inity_offset;
	float		initgrid_scale;
	float		grid_scale;
	float		dda_dx;
	float		dda_dy;
	float		dda_slope;
	float		dda_step;
	float		color_gradient;
	float		color_select;
	float		range_z;
}	t_map_data;

// INITIALIZE MATRIX
void		map_data(t_map_data *data, int argc, char **argv);
void		ft_check_args(int argc, char **argv);
void		set_values(t_map_data *data);
void		ft_matrix_fill(t_map_data *data, int index, char **argv);
int			ft_argv_len(char **argv);
void		data_init(t_map_data *data, char *argv);
void		matrix_get_size(t_map_data *data, char *argv);
void		matrix_init(t_map_data *data, int fd);
void		check_fd(char *argv);
void		free_dpointer(char **pointer, void *str, int d);
void		free_matrixdata(t_map_data *data);
int			get_fd(char *argv);
void		error(char **split_str, char *nextline, int d);
void		map_points(t_map_data *data);
t_map_point	set_coordinate(float x, float y, float z);
t_color_point set_color(char *str);
t_color_point	hex_to_dec_8(char *str);
t_color_point	hex_to_dec_10(char *str);
int			hex_conv(char c);
// MLX
void		img_mlx_pixel_put(t_map_data *data, int x, int y, int color);
//rotation
t_map_point	get_rotationpoints(t_map_point a, t_map_data *data);
t_map_point	get_isometricpoints(t_map_point a);
t_map_point	rotation_x(t_map_point a, t_map_data *data);
t_map_point	rotation_y(t_map_point a, t_map_data *data);
t_map_point	rotation_z(t_map_point a, t_map_data *data);
//screen
void		zoom_out(t_map_data *data);
void		zoom_in(t_map_data *data);
void		set_screen(t_map_data *data);
//DDA
void		map_draw(t_map_data *data);
void		draw_line(t_map_data *data, t_map_point p1, t_map_point p2, t_color_point pc1, t_color_point pc2);
void		draw_params(t_map_data *data, t_map_point p1, t_map_point p2);
//HOOKS
void		handle_rotation(int keysym, t_map_data *data);
void		handle_offset(int keysym, t_map_data *data);
int			handle_keypress(int keysym, t_map_data *data);
void		handle_projection(int keysym, t_map_data *data);
void		handle_scale(int keysym, t_map_data *data);
void		handle_z(int keysym, t_map_data *data);
void		hook_setdefault(t_map_data *data);
void		find_maxmin(t_map_data *data);
void		clean_img(t_map_data *data);
int			ft_close(t_map_data *data);
void		reset_values(t_map_data *data);
void		ft_menu(t_map_data *data);
void		ft_menu_extension(t_map_data *data);
void		projection_type(t_map_data *data);
//COLOR
t_color_point get_color_val(float percent, t_color_point p1, t_color_point p2);
int	percent_to_color(float percent, t_map_data *data, t_color_point p1, t_color_point p2);
int	create_trgb(int t, int r, int g, int b);
#endif