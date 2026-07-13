/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:34:33 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/07/06 20:41:51 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	calculate_wall_x(t_ray *ray, t_scene *scene)
{
	if (ray->side == 0)
		ray->wall_x = scene->player.pos_y
			+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = scene->player.pos_x
			+ ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

t_tex_img	*get_wall_texture(t_scene *scene, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x < 0)
			return (&scene->textures[3]);
		return (&scene->textures[2]);
	}
	if (ray->ray_dir_y < 0)
		return (&scene->textures[0]);
	return (&scene->textures[1]);
}

void	calculate_tex_x(t_ray *ray, t_scene *scene)
{
	t_tex_img	*tex;

	tex = get_wall_texture(scene, ray);
	ray->tex_x = (int)(ray->wall_x * tex->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = tex->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = tex->width - ray->tex_x - 1;
}
