
#ifndef MY_MLX_H
# define MY_MLX_H

#include "../libft/libft.h"

typedef struct s_img
{
	int		width;      // Ancho de la imagen en píxeles
	int		height;     // Alto de la imagen en píxeles

	void	*img;       // Puntero a la imagen de MiniLibX

	char	*addr;      // Dirección de memoria donde están los píxeles

	int		bpp;        // Bits por pixel (calidad / formato del color)
	int		line_len;   // Número de bytes por línea de la imagen
	int		endian;     // Orden de bytes (little/big endian)
}	t_img;

/*
** Pinta un píxel en una posición concreta de la imagen
*/
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);

/*
** Obtiene el color de un píxel en una posición concreta
*/
unsigned int	my_mlx_pixel_get(t_img *img, int x, int y);

/*
** Rellena un área rectangular con un color sólido
*/
void			my_mlx_area_fill(t_img *img, int x, int y, int w, int h, int color);

/*
** Dibuja una línea vertical en la pantalla
** (útil para raycasting en cub3D)
*/
void			my_mlx_draw_vline(t_img *img, int x, int y_start, int y_end, int color);

/*
** Carga una imagen XPM desde un archivo y la convierte en t_img
*/
t_img			*my_mlx_load_xpm(void *mlx, char *path);

/*
** Copia una imagen dentro de otra imagen (blit)
** Ignora el color "transparent_color"
*/
void			my_mlx_blit_img(int pos[2], t_img *src, t_img *dst, 
	int transparent_color);

/*
** Inicializa una estructura de imagen vacía
*/
void			my_mlx_init_img(t_img *img);

/*
** Libera una imagen de memoria
*/
void			my_mlx_destroy_img(void *mlx, t_img *img);
#endif

/*
** endian indica el orden en el que se almacenan los bytes en memoria.
**
** Cuando un color o número se guarda en memoria, está formado por varios bytes.
** El endian define si el byte más importante se guarda primero o el último.
**
** - Little endian (lo más común en PCs):
**   el byte menos importante se guarda primero.
**
** - Big endian:
**   el byte más importante se guarda primero.
**
** En MiniLibX, este valor se usa para interpretar correctamente
** cómo están organizados los píxeles en la imagen en memoria.
**
** Esto es necesario porque la CPU no “entiende colores” directamente:
** solo lee bytes crudos en memoria. Sin saber el endian,
** el programa podría interpretar mal el color de cada píxel
** (por ejemplo, intercambiar rojo, verde y azul o producir colores incorrectos)
**
** Normalmente no necesitas manipularlo directamente,
** solo guardarlo y pasarlo junto con la imagen.
*/