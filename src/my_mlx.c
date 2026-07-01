/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 10:23:04 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/06/11 13:09:47 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

# define WIN_W 1280
# define WIN_H 720

static int	init_mlx_window(t_scene *scene)
{
	scene->graph.mlx = mlx_init();
	if (!scene->graph.mlx)
		return (-1);
	scene->graph.win = mlx_new_window(scene->graph.mlx,
			scene->graph.win_w, scene->graph.win_h, "cub3D");
	if (!scene->graph.win)
		return (-1);
	return (0);
}

static int	init_mlx_image(t_scene *scene)
{
	scene->graph.img = mlx_new_image(scene->graph.mlx,
			scene->graph.win_w, scene->graph.win_h);
	if (!scene->graph.img)
		return (-1);
	scene->graph.addr = mlx_get_data_addr(scene->graph.img,
			&scene->graph.bpp,
			&scene->graph.line_len,
			&scene->graph.endian);
	return (0);
}

static void	init_mlx_hooks(t_scene *scene)
{
	mlx_hook(scene->graph.win, 2, 1L << 0, handle_keypress, scene);
	mlx_hook(scene->graph.win, 17, 0, handle_close, scene);
}

int	graph_init(t_scene *scene)
{
	scene->graph.win_w = WIN_W;
	scene->graph.win_h = WIN_H;
	if (init_mlx_window(scene) != 0)
		return (-1);
	if (init_mlx_image(scene) != 0)
		return (-1);
	render_frame(scene);
	init_mlx_hooks(scene);
	return (0);
}