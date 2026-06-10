/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 10:23:04 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/06/10 13:28:04 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define WIN_W 1280
#define WIN_H 1280

int	graph_init(t_scene *scene)
{
	scene->graph.win_w = WIN_W;
	scene->graph.win_h = WIN_H;

	scene->graph.mlx = mlx_init();
	if (!scene->graph.mlx)
	{
		write(2, "mlx_init failed\n", 16);
		return (-1);
	}
	write(2, "mlx_init OK\n", 12);

	scene->graph.win = mlx_new_window(scene->graph.mlx,
			scene->graph.win_w, scene->graph.win_h, "cub3D");
	if (!scene->graph.win)
	{
		write(2, "mlx_new_window failed\n", 22);
		return (-1);
	}
	write(2, "mlx_new_window OK\n", 18);

	scene->graph.img = mlx_new_image(scene->graph.mlx,
			scene->graph.win_w, scene->graph.win_h);
	if (!scene->graph.img)
	{
		write(2, "mlx_new_image failed\n", 21);
		return (-1);
	}
	write(2, "mlx_new_image OK\n", 17);

	scene->graph.addr = mlx_get_data_addr(scene->graph.img,
			&scene->graph.bpp,
			&scene->graph.line_len,
			&scene->graph.endian);
	write(2, "graph_init complete\n", 20);
	return (0);
}
