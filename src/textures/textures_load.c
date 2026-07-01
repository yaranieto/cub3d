/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:06:51 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/06/12 16:10:43 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static	int	load_one_texture(void *mlx, char *path, t_tex_img *tex)
{
	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		return (-1);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
	return (0);
}

void	free_textures(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (scene->textures[i].img)
			mlx_destroy_image(scene->graph.mlx,
				scene->textures[i].img);
		i++;
	}
}

int	load_textures(t_scene *scene)
{
	void	*mlx;

	mlx = scene->graph.mlx;
	if (load_one_texture(mlx, scene->tex.north, &scene->textures[0]))
	{
		printf("Error NO\n");
		return (-1);
	}
	if (load_one_texture(mlx, scene->tex.south, &scene->textures[1]))
	{
		printf("Error SO\n");
		return (-1);
	}
	if (load_one_texture(mlx, scene->tex.east, &scene->textures[2]))
	{
		printf("Error EA\n");
		return (-1);
	}
	if (load_one_texture(mlx, scene->tex.west, &scene->textures[3]))
	{
		printf("Error WE\n");
		return (-1);
	}
	return (0);
}
