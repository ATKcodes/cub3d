/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:57:41 by amaso             #+#    #+#             */
/*   Updated: 2023/09/20 19:57:44 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gnl/get_next_line.h"
#include "minilibx-linux/mlx.h"
#define WIN_SIZE_H 1080
#define TILE_SIZE 64
#define WIN_SIZE_W 1920
#define MOVESTEP 0.25
#define ROTATE_G 0.15

typedef struct s_render_info
{
	double					tex_pos;
	int						tex_x;
	int						tex_y;
	double					ratio;
	int						line_height;
	int						start_y;
	int						end_y;
}	t_render_info;

typedef struct s_point {
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
}	t_point;

typedef struct s_data {
	char	*path;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		flag;
}	t_data;

typedef struct s_color {
	int	red;
	int	green;
	int	blue;
	int	flag;
	int	hex;
}	t_color;

typedef struct s_player {
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	t_point		plane;
	char		view;
}	t_player;

typedef struct s_ray {
	t_point	ray_dir;
	t_point	side_dist;
	t_point	delta_dist;
	int		map_x;
	int		map_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	double	ratio;
}	t_ray;

typedef struct s_info {
	t_color	ceiling;
	t_color	floor;
	t_data	so;
	t_data	no;
	t_data	ea;
	t_data	we;
	int		start_map;
	int		count_info;
}	t_info;

typedef struct s_mlx {
	void	*mlx_init;
	void	*mlx_win;
	t_data	img;
}	t_mlx;

typedef struct s_pars {
	int			fd;
	int			x;
	int			y;
	char		**matrix;
	char		*gnl;
	int			rows;
	int			comma_counter;
	int			i;
	int			a;
	int			counter;
	int			color;
	char		*str;
	int			space_flag;
	t_info		info;
	t_player	player;
	t_mlx		mlx;
}	t_pars;

//error.c
void			ft_error(char *str);

//cub3d_utils.c
int				ft_gnllen(char *str);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_is_comma_num(int c, t_pars *pars);
void			*ft_calloc(size_t nmeb, size_t size);

//cub3d_utils2.c
void			*ft_memset(void *s, int c, size_t n);

//info_gather.c
void			get_info(t_pars *pars);

//parsing.c
void			check_characters(t_pars *pars);
void			check_borders(t_pars *pars);
void			check_rows(t_pars *pars);
void			check_rows2(t_pars *pars);
void			count_rows(t_pars *pars);

//save_param.c
void			init_flags(t_pars *pars);
void			save_north(t_pars *pars);
void			save_south(t_pars *pars);
void			save_east(t_pars *pars);
void			save_west(t_pars *pars);

//save_param2.c
void			save_background(t_pars *pars);
void			background_cycle(t_pars *pars);
void			save_colors(t_pars *pars);

//save_param3.c
void			xpm_init(t_pars *pars);
void			xpm_init2(t_pars *pars);

//open_window.c
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			new_window(t_pars *pars);
void			rgb_to_hex(t_pars *pars);
void			set_orientation(t_pars *pars);
void			set_plane(t_pars *pars);

///raycast.c
void			set_ray(t_pars *pars, t_ray *ray, double camera_x);
void			draw_game(t_pars *pars);
t_ray			raycast(t_pars *pars, double camera_x);
void			set_perp_wall_dist(t_ray *ray, t_pars *pars);
void			update_ray(t_ray *ray, int axis);

//raycast_utils.c
void			set_step(t_ray *ray);
void			set_delta_dist(t_ray *ray);
void			set_side_dist(t_ray *ray, t_pars *pars);
void			rotate_player(t_pars *pars, int key, double angle);

//moves.c
int				moves(int key, t_pars *pars);
void			moves_loop(t_pars *pars, int key);
void			moves_loop2(t_pars *pars, int key);
void			update_player_position(t_pars *temp, int key);
int				check_wall_collision(t_pars *pars, int key);

//free.c
void			free_images(t_pars *pars);
void			free_all(t_pars	*pars);
void			free_matrix(t_pars	*pars);

//render.c
void			draw_wall(t_pars *pars, t_ray *ray, int x);
void			draw_pixel(t_data *data, int x, int y, int color);
unsigned int	get_img_color(t_data *data, int x, int y);
int				get_texture_scaled_x(t_pars *pars, t_ray *ray);
t_render_info	get_render_info(t_ray *ray, t_pars *pars);
