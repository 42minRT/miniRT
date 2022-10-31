# include "../../include/window.h"
#include "../../include/vector_utils.h"
#include "../../include/trace.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_pixel(t_data *img, t_color3 pixel_color, int i, int j)
{

	int trgb;

	trgb = create_trgb((0),
				(int)(255.999 * pixel_color.x),
                (int)(255.999 * pixel_color.y),
                (int)(255.999 * pixel_color.z));
	my_mlx_pixel_put(img, i, j, trgb);
}

void	draw_image(t_scene *scene, t_data *img)
{
    int			i;
    int			j;
    double      u;
    double      v;
	t_color3	pixel_color;

    j = scene->canvas.height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < scene->canvas.width - 1)
        {
            u = (double)i / (scene->canvas.width - 1);
            v = (double)j / (scene->canvas.height - 1);
            scene->ray = ray_primary(&scene->camera, u, v);
            pixel_color = ray_color(scene);
			draw_pixel(img, pixel_color, i, scene->canvas.height - j);
            ++i;
        }
    --j;
    }
}
