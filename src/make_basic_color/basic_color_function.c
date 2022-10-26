#include "../../include/color.h"


t_color3 set_color_rgb(double r, double g, double b)
{
    t_color3 color;

    color.x = r;
    color.y = g;
    color.z = b;
    return (color);
}

t_color3 red(void)
{
    return (set_color_rgb(255, 0, 0));
}

t_color3 green(void)
{
    return (set_color_rgb(0, 255, 0));
}

t_color3 blue(void)
{
    return (set_color_rgb(0, 0, 255));
}

t_color3 white(void)
{
    return (set_color_rgb(255, 255, 255));
}

t_color3 black(void)
{
    return (set_color_rgb(0, 0, 0));
}


// 테스트 용 main 문
// int main(int argc, char **argv)
// {
//     int     canvas_width;
//     int     canvas_height;

//     canvas_width = 3;
//     canvas_height = 2;
//     printf("P3\n%d %d\n255\n", canvas_width, canvas_height);
//     write_color(red());
//     write_color(green());
//     write_color(blue());
//     write_color(white());
//     write_color(black());   
//     write_color(blue());
//     return (0);
// }
