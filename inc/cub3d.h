/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaranietosantos <yaranietosantos@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:54:35 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/06/14 13:42:57 by yaranietosa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "keycodes.h"
# include "my_mlx.h"
# ifndef OSX
#  include "../minilibx-linux/mlx.h"
# endif
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef FOV
#  define FOV 0.66
# endif

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
}				t_player;

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
}				t_scene;

void	scene_init(t_scene *scene);
void	scene_free(t_scene *scene);
void	scene_free_tex(t_textures *tex);
void	scene_free_map(t_map *map);

int		is_cub_extension(const char *file);
void	free_split(char **arr);

int		load_cub_raw(const char *path, t_scene *scene);
int		validate_scene(t_scene *scene);
int		validate_map_closed(t_scene *scene);

int		parse_line(char *line, t_scene *scene);
int		parse_texture_line(char *line, t_scene *scene);
int		parse_color_line(char *line, t_scene *scene);
int		parse_map_line(char *line, t_scene *scene);
int		load_texture(char *id, char *path, t_scene *scene);

int		create_rgb(t_rgb c);
t_rgb	create_rgbt(int col);
t_rgb	*get_color(char type, t_scene *scene, int **flag);
int		is_color_line(const char *line);
int		is_texture_line(const char *line);

void	init_player_dir(t_player *player);
void	normalize_player_cells(t_map *map);

#endif
