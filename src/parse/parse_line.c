/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:41:51 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/06/14 00:00:00 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int	handle_empty_trim(char *trim, t_scene *scene)
{
	int	ret;

	if (scene->parsing_map)
		ret = -1;
	else
		ret = 0;
	free(trim);
	return (ret);
}

static char	*prepare_line(char *line, t_scene *scene)
{
	size_t	len;

	if (scene->parsing_map || looks_like_map(line))
	{
		len = ft_strlen(line);
		if (len && line[len - 1] == '\n')
			return (ft_substr(line, 0, len - 1));
		return (ft_strdup(line));
	}
	return (ft_strtrim(line, " \t\n"));
}

static int	dispatch_line(char *trim, t_scene *scene)
{
	if (!scene->parsing_map && is_texture_line(trim))
		return (parse_texture_line(trim, scene));
	if (!scene->parsing_map && is_color_line(trim))
		return (parse_color_line(trim, scene));
	if (scene->parsing_map || looks_like_map(trim))
	{
		scene->parsing_map = 1;
		return (parse_map_line(trim, scene));
	}
	return (-1);
}

int	parse_line(char *line, t_scene *scene)
{
	char	*trim;
	int		ret;

	trim = prepare_line(line, scene);
	if (!trim)
		return (-1);
	if (trim[0] == '\0')
		return (handle_empty_trim(trim, scene));
	ret = dispatch_line(trim, scene);
	free(trim);
	return (ret);
}
