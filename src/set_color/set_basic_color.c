#include "../../include/color.h"

t_color3	red(void)
{
	return (set_color_rgb(255, 0, 0));
}

t_color3	green(void)
{
	return (set_color_rgb(0, 255, 0));
}

t_color3	blue(void)
{
	return (set_color_rgb(0, 0, 255));
}

t_color3	white(void)
{
	return (set_color_rgb(255, 255, 255));
}

t_color3	black(void)
{
	return (set_color_rgb(0, 0, 0));
}
