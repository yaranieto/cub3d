/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:54:35 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/07/10 18:30:22 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "keycodes.h"
# include "my_mlx.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

#ifndef FOV
# define FOV 0.06
#endif

#ifndef MOVE_SPEED
# define MOVE_SPEED 0.03
#endif

#ifndef ROT_SPEED
# define ROT_SPEED 0.001
#endif

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}				t_textures;

typedef struct s_maps
{
	char	**grid;
	size_t	rows;
	size_t	cols;
}				t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	spawn_ori;
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_left;
	int		key_right;
}	t_player;

typedef struct s_graph
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		win_w;
	int		win_h;
}				t_graph;

typedef struct s_tex_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_tex_img;

typedef struct s_ray
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

	double	perp_wall_dist;

	int		step_x;
	int		step_y;

	int		hit;
	int		side;

	int		line_height;
	int		draw_start;
	int		draw_end;

	double	wall_x;
	int		tex_x;
}	t_ray;

typedef struct s_scene
{
	int			parsing_map;
	int			has_floor;
	int			has_ceil;
	int			player_count;
	t_textures	tex;
	t_rgb		floor;
	t_rgb		ceil;
	t_map		map;
	t_player	player;
	t_graph		graph;
	t_tex_img	textures[4];
}				t_scene;



void	scene_init(t_scene *scene);
void	scene_free(t_scene *scene);
void	scene_free_tex(t_textures *tex);
void	scene_free_map(t_map *map);

int		is_cub_extension(const char *file);
void	free_split(char **arr);

int		load_cub_raw(const char *path, t_scene *scene);
int		validate_scene(t_scene *scene);

int		parse_line(char *line, t_scene *scene);
int		parse_texture_line(char *line, t_scene *scene);
int		parse_color_line(char *line, t_scene *scene);
int		parse_map_line(char *line, t_scene *scene);
int		load_texture(char *id, char *path, t_scene *scene);

int		create_rgb(t_rgb c);
t_rgb	create_rgbt(int col);
t_rgb	*get_color(char type, t_scene *scene, int **flag);
int		is_color_line(const char *line);

void	init_player_dir(t_player *player);
void	normalize_player_cells(t_map *map);



int		graph_init(t_scene *scene);
void	pixel_put(t_graph *graph, int x, int y, int color);
void	render_frame(t_scene *scene);
int		handle_keypress(int keycode, t_scene *scene);
int		handle_close(t_scene *scene);
int		load_textures(t_scene *scene);
void	free_textures(t_scene *scene);
void	render_walls(t_scene *scene);
void	init_ray(t_ray *ray, t_scene *scene, int x);
void	init_side_dist(t_ray *ray, t_scene *scene);
void	perform_dda(t_ray *ray, t_scene *scene);
void	calculate_wall_distance(t_ray *ray, t_scene *scene);
void	calculate_wall_height(t_ray *ray, t_scene *scene);
void	draw_wall_column(t_scene *scene, t_ray *ray, int x);
void	calculate_wall_x(t_ray *ray, t_scene *scene);
void	calculate_tex_x(t_ray *ray, t_scene *scene);
int		get_texture_pixel(t_tex_img *tex, int x, int y);
t_tex_img	*get_wall_texture(t_scene *scene, t_ray *ray);
void	move_forward(t_scene *scene);
void	rotate_player(t_player *player, double angle);
void	move_player(t_scene *scene, int keycode);
int	handle_keyrelease(int keycode, t_scene *scene);
int	update_game(t_scene *scene);

#endif
