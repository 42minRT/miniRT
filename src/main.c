#include "../include/parse.h"
#include "../include/print.h"
#include "../include/structures.h"
#include "../include/vector_utils.h"
#include "../include/object_utils.h"
#include "../include/color.h"
#include "../include/scene.h"
#include "../include/trace.h"
#include "../include/window.h"
#include "../mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_scene		*scene;
	t_rt_list	*file;
	t_error		err;
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		img;

	err = parse_file(argc, argv, &file);
	if (err != NO_ERROR)
		return (print_error(err));
	scene = init_scene(file);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(
			mlx_ptr, scene->canvas.width,
			scene->canvas.height, "Hellow World!");
	img.img = mlx_new_image(
			mlx_ptr, scene->canvas.width, scene->canvas.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_image(scene, &img);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_hook(win_ptr, X_EVENT_KEY_PRESS, 0, &handle_key, NULL);
	mlx_hook(win_ptr, X_EVENT_CLOSE, 0, &close_window, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
