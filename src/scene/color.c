/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 16:13:25 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/05/31 16:14:15 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	create_rgb(t_rgb c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}

t_rgb	create_rgbt(int col)
{
	t_rgb	c;

	c.r = (col >> 16) & 0xFF;
	c.g = (col >> 8) & 0xFF;
	c.b = col & 0xFF;
	return (c);
}

t_rgb	*get_color(char type, t_scene *scene, int **flag)
{
	if (type == 'F')
		return (*flag = &scene->has_floor, &scene->floor);
	if (type == 'C')
		return (*flag = &scene->has_ceil, &scene->ceil);
	return (NULL);
}

int	is_color_line(const char *line)
{
	return ((line[0] == 'F' || line[0] == 'C')
		&& (line[1] == ' ' || line[1] == '\0'));
}
