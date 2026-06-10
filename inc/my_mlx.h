/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovoa-a <jnovoa-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:56:08 by ynieto-s          #+#    #+#             */
/*   Updated: 2026/06/10 12:28:03 by jnovoa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H

# include "../libft/libft.h"

typedef struct s_img
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/* Prototipos de las funciones de MiniLibX */
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int	my_mlx_pixel_get(t_img *img, int x, int y);
void			my_mlx_area_fill(t_img *img, int x, int y, int w, int h, int color);
void			my_mlx_draw_vline(t_img *img, int x, int y_start, int y_end, int color);
t_img			*my_mlx_load_xpm(void *mlx, char *path);
void			my_mlx_blit_img(int pos[2], t_img *src, t_img *dst, int transparent_color);
void			my_mlx_init_img(t_img *img);
void			my_mlx_destroy_img(void *mlx, t_img *img);

/*
** Explicación del Endian de tu compañera:
** Little endian (común en PCs): el byte menos importante se guarda primero.
** Big endian: el byte más importante se guarda primero.
** MiniLibX lo usa para interpretar los píxeles en memoria.
*/

#endif