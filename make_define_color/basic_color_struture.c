#include <stdio.h>

typedef struct s_basic_color t_basic_color;
typedef struct s_color t_color;

struct s_color
{
    double r;
    double g;
    double b;
};

struct s_basic_color
{
    t_color red;
    t_color green;
    t_color blue;
    t_color white;
    t_color black;
};

t_color set_color_rgb(double r, double g, double b)
{
    t_color color;

    color.r = r;
    color.g = g;
    color.b = b;
    return (color);
}

void    set_basic_color(t_basic_color *basic_colors)
{
    basic_colors->red = set_color_rgb(255, 0, 0);
    basic_colors->green = set_color_rgb(0, 255, 0);
    basic_colors->blue = set_color_rgb(0, 0, 255);
    basic_colors->white = set_color_rgb(255, 255, 255);
    basic_colors->black = set_color_rgb(0, 0, 0);
}

int main(int argc, char **argv)
{
    t_basic_color basic_colors;

    int     canvas_width;
    int     canvas_height;

    canvas_width = 3;
    canvas_height = 2;

    printf("P3\n%d %d\n255\n", canvas_width, canvas_height);
    set_basic_color(&basic_colors);
    printf("%d %d %d\n", (int)basic_colors.red.r, (int)basic_colors.red.g, (int)basic_colors.red.b); // red
    printf("%d %d %d\n", (int)basic_colors.green.r, (int)basic_colors.green.g, (int)basic_colors.green.b); // green
    printf("%d %d %d\n", (int)basic_colors.blue.r, (int)basic_colors.blue.g, (int)basic_colors.blue.b); // blue
    printf("%d %d %d\n", (int)basic_colors.white.r, (int)basic_colors.white.g, (int)basic_colors.white.b); // white
    printf("%d %d %d\n", (int)basic_colors.black.r, (int)basic_colors.black.g, (int)basic_colors.black.b); // black
    printf("%d %d %d\n", (int)basic_colors.red.r, (int)basic_colors.red.g, (int)basic_colors.red.b); // red
    return (0);
}
