/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:58:45 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/05/31 14:59:11 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	config_complete(t_scene *scene)
{
	if (!scene->tex.north || !scene->tex.south
		|| !scene->tex.east || !scene->tex.west)
		return (0);
	if (!scene->has_floor || !scene->has_ceil)
		return (0);
	if (!scene->parsing_map || scene->map.rows == 0)
		return (0);
	if (scene->player_count != 1)
		return (0);
	return (1);
}

static int	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	flood(t_map *map, size_t r, size_t c)
{
	char	**g;

	g = map->grid;
	if (r >= map->rows || c >= map->cols)
		return (0);
	if (g[r][c] == '1' || g[r][c] == 'V')
		return (1);
	if (g[r][c] == ' ')
		return (0);
	if (!is_walkable(g[r][c]))
		return (0);
	g[r][c] = 'V';
	if (r > 0 && !flood(map, r - 1, c))
		return (0);
	if (r + 1 < map->rows && !flood(map, r + 1, c))
		return (0);
	if (c > 0 && !flood(map, r, c - 1))
		return (0);
	if (c + 1 < map->cols && !flood(map, r, c + 1))
		return (0);
	return (1);
}

static int	map_closed(t_scene *scene)
{
	size_t	r;
	size_t	c;

	r = (size_t)scene->player.pos_y;
	c = (size_t)scene->player.pos_x;
	return (flood(&scene->map, r, c));
}

static void	normalize_player_cells(t_map *map)
{
	size_t	r;
	size_t	c;

	r = 0;
	while (r < map->rows)
	{
		c = 0;
		while (c < map->cols)
		{
			if (map->grid[r][c] == 'N' || map->grid[r][c] == 'S'
				|| map->grid[r][c] == 'E' || map->grid[r][c] == 'W')
				map->grid[r][c] = '0';
			c++;
		}
		r++;
	}
}

int	validate_scene(t_scene *scene)
{
	if (!config_complete(scene))
		return (-1);
	if (!map_closed(scene))
		return (-1);
	normalize_player_cells(&scene->map);
	return (0);
}
