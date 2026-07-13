/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:10:52 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/07/09 17:08:17 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	move_if_possible(t_scene *scene, double new_x, double new_y)
{
	if (scene->map.grid[(int)scene->player.pos_y][(int)new_x] != '1')
		scene->player.pos_x = new_x;
	if (scene->map.grid[(int)new_y][(int)scene->player.pos_x] != '1')
		scene->player.pos_y = new_y;
}

static void	move_forward_backward(t_scene *scene, int dir)
{
	move_if_possible(
		scene,
		scene->player.pos_x + scene->player.dir_x * MOVE_SPEED * dir,
		scene->player.pos_y + scene->player.dir_y * MOVE_SPEED * dir);
}

static void	move_left_right(t_scene *scene, int dir)
{
	move_if_possible(
		scene,
		scene->player.pos_x + scene->player.plane_x * MOVE_SPEED * dir,
		scene->player.pos_y + scene->player.plane_y * MOVE_SPEED * dir);
}

void	move_player(t_scene *scene, int keycode)
{
	if (keycode == KEY_W)
		move_forward_backward(scene, 1);
	else if (keycode == KEY_S)
		move_forward_backward(scene, -1);
	else if (keycode == KEY_D)
		move_left_right(scene, 1);
	else if (keycode == KEY_A)
		move_left_right(scene, -1);
}

