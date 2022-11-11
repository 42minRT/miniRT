#ifndef WINDOW_H
# define WINDOW_H

# include <stdio.h>
# include "structures.h"

void	draw_pixel(t_data *img, t_color3 pixel_color, int i, int j);
void	draw_image(t_scene *scene);
void	handle_key(int keycode, void *arg);
void	close_window(int status);

#endif
