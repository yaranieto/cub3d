/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:58:45 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/06/14 00:00:00 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	config_complete(t_scene *scene)
{
	if (!scene->tex.north || !scene->tex.south
		|| !scene->tex.east || !scene->tex.west)
		return (0);
	if (!scene->has_floor || !scene->has_ceil)
		return (0);
	if (!scene->parsing_map || scene->map.rows == 0)
		return (0);
	if (scene->player_count != 1)
		return (0);
	return (1);
}

int	validate_scene(t_scene *scene)
{
	if (!config_complete(scene))
		return (-1);
	if (validate_map_closed(scene) != 0)
		return (-1);
	return (0);
}
