#include <stdio.h>

typedef struct s_color t_color;

struct s_color
{
    double r;
    double g;
    double b;
};

t_color set_color_rgb(double r, double g, double b)
{
    t_color color;

    color.r = r;
    color.g = g;
    color.b = b;
    return (color);
}

t_color red(void)
{
    return (set_color_rgb(255, 0, 0));
}

t_color green(void)
{
    return (set_color_rgb(0, 255, 0));
}

t_color blue(void)
{
    return (set_color_rgb(0, 0, 255));
}

t_color white(void)
{
    return (set_color_rgb(255, 255, 255));
}

t_color black(void)
{
    return (set_color_rgb(0, 0, 0));
}

void    write_color(t_color pixel_color)
{
    printf("%d %d %d\n", (int)(pixel_color.r),
                         (int)(pixel_color.g),
                         (int)(pixel_color.b)
    );
}

int main(int argc, char **argv)
{
    int     canvas_width;
    int     canvas_height;

    canvas_width = 3;
    canvas_height = 2;
    printf("P3\n%d %d\n255\n", canvas_width, canvas_height);
    write_color(red());
    write_color(green());
    write_color(blue());
    write_color(white());
    write_color(black());   
    write_color(blue());
    return (0);
}