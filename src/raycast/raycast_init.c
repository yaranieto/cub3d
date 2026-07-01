/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 01:49:05 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/06/29 13:46:46 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	init_delta_dist(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void	init_steps(t_ray *ray)
{
	if (ray->ray_dir_x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_dir_y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
}

void	init_ray(t_ray *ray, t_scene *scene, int x)
{
	ray->camera_x = 2.0 * x
		/ (double)scene->graph.win_w - 1.0;
	ray->ray_dir_x = scene->player.dir_x
		+ scene->player.plane_x * ray->camera_x;
	ray->ray_dir_y = scene->player.dir_y
		+ scene->player.plane_y * ray->camera_x;
	ray->map_x = (int)scene->player.pos_x;
	ray->map_y = (int)scene->player.pos_y;
	init_delta_dist(ray);
	init_steps(ray);
	init_side_dist(ray, scene);
}
