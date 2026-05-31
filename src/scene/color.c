

#include "cub3d.h"

int	create_rgb(t_rgb c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}

t_rgb	create_rgbt(int col)
{
	t_rgb	c;

	c.r = (col >> 16) & 0xFF;
	c.g = (col >> 8) & 0xFF;
	c.b = col & 0xFF;
	return (c);
}
