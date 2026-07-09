/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:04:41 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/07/06 14:04:51 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_forward(t_scene *scene)
{
	double	speed;

	speed = 0.10;
	scene->player.pos_x += scene->player.dir_x * speed;
	scene->player.pos_y += scene->player.dir_y * speed;
}
