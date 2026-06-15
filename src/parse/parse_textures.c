/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:42:02 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/06/14 00:00:00 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	match_id(const char *line, const char *id)
{
	return (line[0] == id[0] && line[1] == id[1]
		&& (line[2] == ' ' || line[2] == '\0'));
}

int	is_texture_line(const char *line)
{
	return (match_id(line, "NO") || match_id(line, "SO")
		|| match_id(line, "WE") || match_id(line, "EA"));
}
