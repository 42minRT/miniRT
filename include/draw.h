#ifndef DRAW_PIXEL_H
# define DRAW_PIXEL_H

# include <stdio.h>
# include "structures.h"

void    draw_pixel(t_data *img, t_color3 pixel_color, int i, int j);
void	draw_image(t_scene *scene, t_data *mlx_data);

#endif
