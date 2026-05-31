/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:42:06 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/05/31 13:42:07 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	has_xpm_ext(const char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4)
		return (0);
	return (ft_strncmp(path + len - 4, ".xpm", 4) == 0);
}

int	load_texture(char *id, char *path, t_scene *scene)
{
	char	**slot;

	if (!has_xpm_ext(path))
		return (-1);
	if (ft_strncmp(id, "NO", 2) == 0)
		slot = &scene->tex.north;
	else if (ft_strncmp(id, "SO", 2) == 0)
		slot = &scene->tex.south;
	else if (ft_strncmp(id, "WE", 2) == 0)
		slot = &scene->tex.west;
	else if (ft_strncmp(id, "EA", 2) == 0)
		slot = &scene->tex.east;
	else
		return (-1);
	if (*slot)
		return (-1);
	*slot = ft_strdup(path);
	if (!*slot)
		return (-1);
	return (0);
}

int	parse_texture_line(char *line, t_scene *scene)
{
	char	**sp;

	sp = ft_split(line, ' ');
	if (!sp)
		return (-1);
	if (!sp[0] || !sp[1] || sp[2] || ft_strlen(sp[0]) != 2)
		return (free_split(sp), -1);
	if (load_texture(sp[0], sp[1], scene) != 0)
		return (free_split(sp), -1);
	free_split(sp);
	return (0);
}
