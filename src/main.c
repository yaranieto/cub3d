/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 16:00:48 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/06/12 12:06:13 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_err(const char *msg)
{
	const char	*e;
	size_t		i;

	e = "Error\n";
	i = 0;
	while (e[i])
	{
		write(2, &e[i], 1);
		i++;
	}
	i = 0;
	while (msg[i])
	{
		write(2, &msg[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

static int	arg_ok(int argc)
{
	if (argc == 2)
		return (1);
	print_err("usage: ./cub3D <scene.cub>");
	return (0);
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (!arg_ok(argc))
		return (1);
	if (!is_cub_extension(argv[1]))
		return (print_err("failed to load .cub"), 1);
	scene_init(&scene);
	if (load_cub_raw(argv[1], &scene) != 0)
	{
		scene_free(&scene);
		return (print_err("failed to load .cub"), 1);
	}
	if (graph_init(&scene) != 0)
	{
		scene_free(&scene);
		return (1);
	}
	if (load_textures(&scene) != 0)
	{
		scene_free(&scene);
		return (print_err("failed to load textures"), 1);
	}
	mlx_loop(scene.graph.mlx);
	scene_free(&scene);
	return (0);
}
