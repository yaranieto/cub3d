/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yara <yara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:48:44 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/06/15 19:08:31 by yara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	set_north(t_player *p)
{
	p->dir_x = 0.0;
	p->dir_y = -1.0;
	p->plane_x = FOV;
	p->plane_y = 0.0;
}

static void	set_south(t_player *p)
{
	p->dir_x = 0.0;
	p->dir_y = 1.0;
	p->plane_x = -FOV;
	p->plane_y = 0.0;
}

static void	set_east(t_player *p)
{
	p->dir_x = 1.0;
	p->dir_y = 0.0;
	p->plane_x = 0.0;
	p->plane_y = FOV;
}

static void	set_west(t_player *p)
{
	p->dir_x = -1.0;
	p->dir_y = 0.0;
	p->plane_x = 0.0;
	p->plane_y = -FOV;
}

void	init_player_dir(t_player *player)
{
	if (!player || !player->spawn_ori)
		return ;
	if (player->spawn_ori == 'N')
		set_north(player);
	else if (player->spawn_ori == 'S')
		set_south(player);
	else if (player->spawn_ori == 'E')
		set_east(player);
	else if (player->spawn_ori == 'W')
		set_west(player);
}
