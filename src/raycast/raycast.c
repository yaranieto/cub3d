/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 22:08:45 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/06/30 20:52:31 by jnovoa-a         ###   ########.fr       */
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
		ray.hit = 0;
		perform_dda(&ray, scene);
		calculate_wall_distance(&ray, scene);
		calculate_wall_height(&ray, scene);
		draw_wall_column(scene, &ray, x);
		x++;
	}
}