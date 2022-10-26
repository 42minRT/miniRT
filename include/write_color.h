#ifndef WRITE_COROR_H
# define WRITE_COROR_H

#include <stdio.h>
#include "structures.h"

t_color set_color_rgb(double r, double g, double b);
t_color red(void);
t_color green(void);
t_color blue(void);
t_color white(void);
t_color black(void);
void    write_color(t_color3 pixel_color);

#endif
