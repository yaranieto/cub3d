/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:03:15 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/07/10 18:25:19 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	calculate_wall_height(t_ray *ray, t_scene *scene)
{
	ray->line_height = (int)(scene->graph.win_h
			/ ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2
		+ scene->graph.win_h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2
		+ scene->graph.win_h / 2;
	if (ray->draw_end >= scene->graph.win_h)
		ray->draw_end = scene->graph.win_h - 1;
}

void	draw_wall_column(t_scene *scene, t_ray *ray, int x)
{
	t_tex_img	*tex;
	int			y;
	int			tex_y;
	int			color;

	tex = get_wall_texture(scene, ray);
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (y - ray->draw_start)
			* tex->height / ray->line_height;
		color = get_texture_pixel(tex, ray->tex_x, tex_y);
		pixel_put(&scene->graph, x, y, color);
		y++;
	}
}
