/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:58:36 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/05/31 14:58:37 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == ' ');
}

static int	register_player(t_scene *scene, char c, size_t x, size_t y)
{
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (0);
	scene->player_count++;
	if (scene->player_count > 1)
		return (-1);
	scene->player.spawn_ori = c;
	scene->player.pos_x = (double)x + 0.5;
	scene->player.pos_y = (double)y + 0.5;
	return (0);
}

static int	validate_row_chars(char *line, t_scene *scene, size_t y)
{
	size_t	x;

	x = 0;
	while (line[x])
	{
		if (!is_map_char(line[x]))
			return (-1);
		if (register_player(scene, line[x], x, y) != 0)
			return (-1);
		x++;
	}
	return (0);
}

static int	append_row(t_map *map, char *line)
{
	char	**new_grid;
	size_t	i;
	size_t	len;

	len = ft_strlen(line);
	if (len == 0)
		return (-1);
	if (map->rows > 0 && len != map->cols)
		return (-1);
	new_grid = ft_calloc(map->rows + 1, sizeof(char *));
	if (!new_grid)
		return (-1);
	i = 0;
	while (i < map->rows)
	{
		new_grid[i] = map->grid[i];
		i++;
	}
	new_grid[i] = line;
	free(map->grid);
	map->grid = new_grid;
	map->rows++;
	map->cols = len;
	return (0);
}

int	parse_map_line(char *line, t_scene *scene)
{
	char	*row;
	size_t	y;

	if (!line || !line[0])
		return (-1);
	y = scene->map.rows;
	if (validate_row_chars(line, scene, y) != 0)
		return (-1);
	row = ft_strdup(line);
	if (!row)
		return (-1);
	if (append_row(&scene->map, row) != 0)
		return (free(row), -1);
	return (0);
}
