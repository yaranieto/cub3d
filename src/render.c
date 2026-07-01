/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:10:44 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/06/25 22:15:51 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put(t_graph *graph, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= graph->win_w || y < 0 || y >= graph->win_h)
		return ;
	dst = graph->addr + (y * graph->line_len + x * (graph->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	render_bg_row(t_scene *scene, int y)
{
	int	x;
	int	color;

	if (y < scene->graph.win_h / 2)
		color = create_rgb(scene->ceil);
	else
		color = create_rgb(scene->floor);
	x = 0;
	while (x < scene->graph.win_w)
	{
		pixel_put(&scene->graph, x, y, color);
		x++;
	}
}

void	render_frame(t_scene *scene)
{
	int	y;

	y = 0;
	while (y < scene->graph.win_h)
	{
		render_bg_row(scene, y);
		y++;
	}
	render_walls(scene);
	mlx_put_image_to_window(
		scene->graph.mlx,
		scene->graph.win,
		scene->graph.img,
		0,
		0);
}

int	handle_keypress(int keycode, t_scene *scene)
{
	if (keycode == KEY_ESC)
	{
		scene_free(scene);
		exit(0);
	}
	free_textures(scene);
	return (0);
}

int	handle_close(t_scene *scene)
{
	scene_free(scene);
	free_textures(scene);
	exit(0);
}
