/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 17:59:15 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/07/10 18:33:26 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	update_game(t_scene *scene)
{
	if (scene->player.key_w)
		move_player(scene, KEY_W);
	if (scene->player.key_s)
		move_player(scene, KEY_S);
	if (scene->player.key_a)
		move_player(scene, KEY_A);
	if (scene->player.key_d)
		move_player(scene, KEY_D);
	if (scene->player.key_left)
		rotate_player(&scene->player, -ROT_SPEED);
	if (scene->player.key_right)
		rotate_player(&scene->player, ROT_SPEED);
	render_frame(scene);
	return (0);
}
