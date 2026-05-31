/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:42:02 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/05/31 16:09:36 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_texture_line(const char *line)
{
	return (match_id(line, "NO") || match_id(line, "SO")
		|| match_id(line, "WE") || match_id(line, "EA"));
}
