/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 19:46:28 by jnovoa-a          #+#    #+#             */
/*   Updated: 2026/07/02 19:48:41 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_texture_pixel(t_tex_img *tex, int x, int y)
{
	char	*dst;

	dst = tex->addr
		+ (y * tex->line_len)
		+ (x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}
