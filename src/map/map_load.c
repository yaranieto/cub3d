/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:58:50 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/05/31 14:58:51 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../../gnl/get_next_line.h"

static int	finish_load(t_scene *scene)
{
	if (validate_scene(scene) != 0)
		return (-1);
	normalize_player_cells(&scene->map);
	init_player_dir(&scene->player);
	return (0);
}

int	load_cub_raw(const char *path, t_scene *scene)
{
	int		fd;
	char	*line;

	if (!path || !is_cub_extension(path))
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(line, scene) != 0)
		{
			free(line);
			close(fd);
			gnl_clear_stash();
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	gnl_clear_stash();
	return (finish_load(scene));
}
