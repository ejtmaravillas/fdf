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

# ifdef __APPLE__
#  define W_COMMAND 13
#  define A_COMMAND 0
#  define S_COMMAND 1
#  define D_COMMAND 2
#  define R_COMMAND 15
#  define N_COMMAND 45
#  define M_COMMAND 46
#  define ZO_COMMAND 69
#  define ZI_COMMAND 78
#  define U_COMMAND 32
#  define J_COMMAND 38
#  define I_COMMAND 34
#  define K_COMMAND 40
#  define O_COMMAND 31
#  define L_COMMAND 37
#  define ISO_COMMAND 50
#  define PAR_COMMAND 48
#  define TOP_COMMAND 272
#  define FRN_COMMAND 257
#  define SID_COMMAND 256
#  define ESC_COMMAND 53
#  define COLOR0_COMMAND 82
#  define COLOR1_COMMAND 83
#  define COLOR2_COMMAND 84
#  define COLOR3_COMMAND 85
#  define COLOR4_COMMAND 86
#  define COLOR5_COMMAND 87
#  define COLOR6_COMMAND 88
#  define COLOR7_COMMAND 89
#  define COLOR8_COMMAND 91
#  define COLOR9_COMMAND 92
# endif
# ifdef __linux__
#  define W_COMMAND 119
#  define A_COMMAND 97
#  define S_COMMAND 115
#  define D_COMMAND 100
#  define R_COMMAND 114
#  define N_COMMAND 110
#  define M_COMMAND 109
#  define ZO_COMMAND 65451
#  define ZI_COMMAND 65453
#  define U_COMMAND 117
#  define J_COMMAND 106
#  define I_COMMAND 105
#  define K_COMMAND 107
#  define O_COMMAND 111
#  define L_COMMAND 108
#  define ISO_COMMAND 96
#  define PAR_COMMAND 65289
#  define TOP_COMMAND 65509
#  define FRN_COMMAND 65505
#  define SID_COMMAND 65507
#  define ESC_COMMAND 65307
#  define COLOR1_COMMAND 65436
#  define COLOR2_COMMAND 65433
#  define COLOR3_COMMAND 65435
#  define COLOR4_COMMAND 65430
#  define COLOR5_COMMAND 65437
#  define COLOR6_COMMAND 65432
#  define COLOR7_COMMAND 65429
#  define COLOR8_COMMAND 65431
#  define COLOR9_COMMAND 65434
#  define COLOR0_COMMAND 65438
# endif

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
	int				**data_map;
	char			***color_map;
	t_color_point	**color_point;
	char			*name;
	int				row;
	int				col;
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_map_point		**point_map;
	float			theta_x;
	float			theta_y;
	float			theta_z;
	int				projection;
	float			p_anglex;
	float			p_angley;
	float			max_x;
	float			max_y;
	float			max_z;
	float			min_x;
	float			min_y;
	float			min_z;
	float			x_offset;
	float			y_offset;
	float			z_factor;
	float			initx_offset;
	float			inity_offset;
	float			initgrid_scale;
	float			grid_scale;
	float			dda_dx;
	float			dda_dy;
	float			dda_slope;
	float			dda_step;
	float			color_gradient;
	float			color_select;
	t_color_point			color_a;
	t_color_point			color_b;
	float			range_z;
}	t_map_data;

// INITIALIZE MATRIX
void			map_data(t_map_data *data, int argc, char **argv);
void			ft_check_args(int argc, char **argv);
void			set_values(t_map_data *data);
void			ft_matrix_fill(t_map_data *data, int index, char **argv);
int				ft_argv_len(char **argv);
void			data_init(t_map_data *data, char *argv);
void			matrix_get_size(t_map_data *data, char *argv);
void			matrix_init(t_map_data *data, int fd);
void			check_fd(char *argv);
void			free_dpointer(char **pointer, void *str, int d);
void			free_matrixdata(t_map_data *data);
int				get_fd(char *argv);
void			error(char **split_str, char *nextline, int d);
void			map_points(t_map_data *data);
t_map_point		set_coordinate(float x, float y, float z);
t_color_point	set_color(char *str);
t_color_point	hex_to_dec_8(char *str);
t_color_point	hex_to_dec_10(char *str);
int				hex_conv(char c);
// MLX
void			img_mlx_pixel_put(t_map_data *data, int x, int y, int color);
//rotation
t_map_point		get_rotationpoints(t_map_point a, t_map_data *data);
t_map_point		get_isometricpoints(t_map_point a);
t_map_point		rotation_x(t_map_point a, t_map_data *data);
t_map_point		rotation_y(t_map_point a, t_map_data *data);
t_map_point		rotation_z(t_map_point a, t_map_data *data);
//screen
void			zoom_out(t_map_data *data);
void			zoom_in(t_map_data *data);
void			set_screen(t_map_data *data);
//DDA
void			map_draw(t_map_data *data);
void			draw_line(t_map_data *data, t_map_point p1, t_map_point p2);
void			draw_h(t_map_data *data, t_map_point p1, t_map_point p2);
void			draw_v(t_map_data *data, t_map_point p1, t_map_point p2);
void			draw_params(t_map_data *data, t_map_point p1, t_map_point p2);
//HOOKS
void			handle_rotation(int keysym, t_map_data *data);
void			handle_offset(int keysym, t_map_data *data);
int				handle_keypress(int keysym, t_map_data *data);
void			handle_projection(int keysym, t_map_data *data);
void			handle_scale(int keysym, t_map_data *data);
void			handle_z(int keysym, t_map_data *data);
void			handle_color(int keysym, t_map_data *data);
void			hook_setdefault(t_map_data *data);
void			find_maxmin(t_map_data *data);
void			clean_img(t_map_data *data);
int				ft_close(t_map_data *data);
void			reset_values(t_map_data *data);
void			ft_menu(t_map_data *data);
void			ft_menu_extension(t_map_data *data);
void			projection_type(t_map_data *data);
//COLOR
t_color_point	get_color_val(float percent, t_color_point p1, \
				t_color_point p2);
int				percent_to_color(float percent, t_map_data *data, \
				t_color_point p1, t_color_point p2);
int				create_trgb(int t, int r, int g, int b);
#endif

// LINUX KEYS
// w = 119
// a = 97
// s = 115
// d = 100
// r = 114
// u = 117
// j = 106
// i = 105
// k = 107
// o = 111
// l = 108

// NUMPAD
// 0 = 65438
// 1 = 65436
// 2 = 65433
// 3 = 65435
// 4 = 65430
// 5 = 65437
// 6 = 65432
// 7 = 65429
// 8 = 65431
// 9 = 65434

// ~ == 96
// TAB == 65289
// CAPS == 65509
// LSHIFT == 65505
// LCTRL == 65507

// + = 65451
// - = 65453

// n = 110
// m = 109

// MAC KEYS
// w = 13
// a = 0
// s = 1
// d = 2
// r = 15
// n = 45
// m = 46

// + = 69
// - = 78

// u = 32
// j = 38
// i = 34
// k = 40
// o = 31
// l = 37

// NUMPAD
// 0 = 82
// 1 = 83
// 2 = 84
// 3 = 85
// 4 = 86
// 5 = 87
// 6 = 88
// 7 = 89
// 8 = 91
// 9 = 92

// ~ == 50
// TAB == 48
// CAPS == 272
// LSHIFT == 257
// LCTRL == 256