/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_floodfill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 16:12:33 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/05/31 16:13:09 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	normalize_player_cells(t_map *map)
{
	size_t	r;
	size_t	c;

	r = 0;
	while (r < map->rows)
	{
		c = 0;
		while (c < map->cols)
		{
			if (map->grid[r][c] == 'N' || map->grid[r][c] == 'S'
				|| map->grid[r][c] == 'E' || map->grid[r][c] == 'W')
				map->grid[r][c] = '0';
			c++;
		}
		r++;
	}
}
