/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:41:54 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/05/31 16:02:29 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_rgb_num(const char *s)
{
	int	val;

	if (!s || !*s)
		return (0);
	val = 0;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		val = val * 10 + (*s - '0');
		if (val > 255)
			return (0);
		s++;
	}
	return (1);
}

static int	parse_rgb_value(const char *s, int *out)
{
	int	val;

	if (!is_rgb_num(s))
		return (-1);
	val = 0;
	while (*s)
	{
		val = val * 10 + (*s - '0');
		s++;
	}
	*out = val;
	return (0);
}

static int	fill_rgb(t_rgb *rgb, char **parts)
{
	if (parse_rgb_value(parts[0], &rgb->r) != 0)
		return (-1);
	if (parse_rgb_value(parts[1], &rgb->g) != 0)
		return (-1);
	if (parse_rgb_value(parts[2], &rgb->b) != 0)
		return (-1);
	return (0);
}

static int	parse_rgb_triplet(const char *str, t_rgb *rgb)
{
	char	**parts;

	parts = ft_split(str, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
		return (free_split(parts), -1);
	if (fill_rgb(rgb, parts) != 0)
		return (free_split(parts), -1);
	free_split(parts);
	return (0);
}

int	parse_color_line(char *line, t_scene *scene)
{
	char	**sp;
	t_rgb	*dst;
	int		*flag;

	sp = ft_split(line, ' ');
	if (!sp || !sp[0] || !sp[1] || sp[2] || sp[0][1] != '\0')
		return (free_split(sp), -1);
	dst = get_color(sp[0][0], scene, &flag);
	if (!dst || *flag || parse_rgb_triplet(sp[1], dst))
		return (free_split(sp), -1);
	*flag = 1;
	free_split(sp);
	return (0);
}
