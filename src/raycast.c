#include "wolf.h"

t_coords	set_pixel(int x, int y, int color)
{
	t_coords p;

	p.x = x;
	p.y = y;
	p.color = color;
	return (p);
}
