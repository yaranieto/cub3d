/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:28:48 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/07/10 18:20:33 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_texture_pixel(t_tex_img *tex, int x, int y)
{
	char	*dst;
	if (x < 0 || x >= tex->width)
	{
		return (0);
	}
	if (y < 0 || y >= tex->height)
	{
		return (0);
	}

	dst = tex->addr
		+ (y * tex->line_len)
		+ (x * (tex->bpp / 8));

	return (*(unsigned int *)dst);
}