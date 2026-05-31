/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:41:51 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/05/31 16:08:32 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	match_id(const char *line, const char *id)
{
	return (line[0] == id[0] && line[1] == id[1]
		&& (line[2] == ' ' || line[2] == '\0'));
}

static int	looks_like_map(const char *line)
{
	size_t	i;

	if (!line || !line[0])
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	is_map_line(const char *line, t_scene *scene)
{
	if (scene->parsing_map)
		return (1);
	return (looks_like_map(line));
}

int	parse_line(char *line, t_scene *scene)
{
	char	*trim;
	int		ret;

	trim = ft_strtrim(line, " \t\n");
	if (!trim)
		return (-1);
	if (trim[0] == '\0')
	{
		if (scene->parsing_map)
			ret = -1;
		else
			ret = 0;
		free(trim);
		return (ret);
	}
	if (!scene->parsing_map && is_texture_line(trim))
		ret = parse_texture_line(trim, scene);
	else if (!scene->parsing_map && is_color_line(trim))
		ret = parse_color_line(trim, scene);
	else if (is_map_line(trim, scene))
	{
		scene->parsing_map = 1;
		ret = parse_map_line(trim, scene);
	}
	else
		ret = -1;
	free(trim);
	return (ret);
}
