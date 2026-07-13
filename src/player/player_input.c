/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 17:53:25 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/07/10 17:54:34 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	handle_keypress(int keycode, t_scene *scene)
{
	if (keycode == KEY_ESC)
	{
		scene_free(scene);
		exit(0);
	}
	if (keycode == KEY_W)
		scene->player.key_w = 1;
	else if (keycode == KEY_S)
		scene->player.key_s = 1;
	else if (keycode == KEY_A)
		scene->player.key_a = 1;
	else if (keycode == KEY_D)
		scene->player.key_d = 1;
	else if (keycode == KEY_LEFT)
		scene->player.key_left = 1;
	else if (keycode == KEY_RIGHT)
		scene->player.key_right = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_scene *scene)
{
	if (keycode == KEY_W)
		scene->player.key_w = 0;
	else if (keycode == KEY_S)
		scene->player.key_s = 0;
	else if (keycode == KEY_A)
		scene->player.key_a = 0;
	else if (keycode == KEY_D)
		scene->player.key_d = 0;
	else if (keycode == KEY_LEFT)
		scene->player.key_left = 0;
	else if (keycode == KEY_RIGHT)
		scene->player.key_right = 0;
	return (0);
}