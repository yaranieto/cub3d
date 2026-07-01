/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:07:04 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/06/30 19:07:17 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	calculate_wall_distance(t_ray *ray, t_scene *scene)
{
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->map_x
				- scene->player.pos_x
				+ (1 - ray->step_x) / 2.0)
			/ ray->ray_dir_x;
	}
	else
	{
		ray->perp_wall_dist = (ray->map_y
				- scene->player.pos_y
				+ (1 - ray->step_y) / 2.0)
			/ ray->ray_dir_y;
	}
}