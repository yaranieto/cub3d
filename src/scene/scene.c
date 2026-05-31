/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 16:14:03 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/05/31 16:14:04 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	scene_init(t_scene *scene)
{
	ft_bzero(scene, sizeof(t_scene));
}

void	scene_free_tex(t_textures *tex)
{
	if (!tex)
		return ;
	free(tex->north);
	free(tex->south);
	free(tex->east);
	free(tex->west);
	tex->north = NULL;
	tex->south = NULL;
	tex->east = NULL;
	tex->west = NULL;
}

void	scene_free_map(t_map *map)
{
	size_t	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->rows)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
	map->rows = 0;
	map->cols = 0;
}

void	scene_free(t_scene *scene)
{
	if (!scene)
		return ;
	scene_free_tex(&scene->tex);
	scene_free_map(&scene->map);
}
