/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 22:08:45 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/07/02 20:42:20 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	render_walls(t_scene *scene)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < scene->graph.win_w)
	{
		init_ray(&ray, scene, x);
		printf("dir=(%f,%f)  plane=(%f,%f)\n",
		scene->player.dir_x,
		scene->player.dir_y,
		scene->player.plane_x,
		scene->player.plane_y);

		printf("ray=(%f,%f)\n",
		ray.ray_dir_x,
		ray.ray_dir_y);
		ray.hit = 0;
		perform_dda(&ray, scene);
		calculate_wall_distance(&ray, scene);
		printf("perp=%f\n", ray.perp_wall_dist);
		calculate_wall_x(&ray, scene);
		calculate_tex_x(&ray, scene);
		calculate_wall_height(&ray, scene);
		draw_wall_column(scene, &ray, x);
		x++;
	}
}