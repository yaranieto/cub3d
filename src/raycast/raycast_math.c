/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:54:31 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/06/28 19:54:47 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_side_dist(t_ray *ray, t_scene *scene)
{
	if (ray->ray_dir_x < 0)
	{
		ray->side_dist_x = (scene->player.pos_x
				- ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->side_dist_x = (ray->map_x + 1.0
				- scene->player.pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->side_dist_y = (scene->player.pos_y
				- ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->side_dist_y = (ray->map_y + 1.0
				- scene->player.pos_y) * ray->delta_dist_y;
	}
}