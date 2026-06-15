/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_floodfill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaranietosantos <yaranietosantos@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 16:12:33 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/06/14 13:42:57 by yaranietosa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	g_h;
static size_t	g_w;

static void	free_padded(char **pad, size_t n)
{
	size_t	i;

	if (!pad)
		return ;
	i = 0;
	while (i < n)
	{
		free(pad[i]);
		i++;
	}
	free(pad);
}

static char	**create_padded(t_map *map, size_t *h, size_t *w)
{
	char	**pad;
	size_t	y;

	*h = map->rows + 2;
	*w = map->cols + 2;
	pad = ft_calloc(*h, sizeof(char *));
	if (!pad)
		return (NULL);
	y = 0;
	while (y < *h)
	{
		pad[y] = ft_calloc(*w + 1, sizeof(char));
		if (!pad[y])
			return (free_padded(pad, y), NULL);
		ft_memset(pad[y], ' ', *w);
		if (y > 0 && y < *h - 1)
			ft_memcpy(pad[y] + 1, map->grid[y - 1], map->cols);
		y++;
	}
	return (pad);
}

static void	flood(char **pad, size_t y, size_t x)
{
	char	c;

	if (y >= g_h || x >= g_w)
		return ;
	c = pad[y][x];
	if (c != '0' && c != ' ' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return ;
	pad[y][x] = 'X';
	flood(pad, y - 1, x);
	flood(pad, y + 1, x);
	flood(pad, y, x - 1);
	flood(pad, y, x + 1);
}

static int	map_has_leak(t_map *map, char **pad)
{
	size_t	y;
	size_t	x;
	char	c;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			c = map->grid[y][x];
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (pad[y + 1][x + 1] == 'X')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	validate_map_closed(t_scene *scene)
{
	char	**pad;
	size_t	h;
	size_t	w;

	pad = create_padded(&scene->map, &h, &w);
	if (!pad)
		return (-1);
	g_h = h;
	g_w = w;
	flood(pad, 0, 0);
	if (map_has_leak(&scene->map, pad))
		return (free_padded(pad, h), -1);
	free_padded(pad, h);
	return (0);
}
