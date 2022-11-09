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
	t_data		img;

	err = parse_file(argc, argv, &file);
	if (err != NO_ERROR)
		return (print_error(err));
	scene = init_scene(file);
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(
			img.mlx_ptr, scene->canvas.width,
			scene->canvas.height, "Hellow World!");
	img.img = mlx_new_image(
			img.mlx_ptr, scene->canvas.width, scene->canvas.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_image(scene, &img);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
	mlx_hook(img.win_ptr, X_EVENT_KEY_PRESS, 0, (void *)&handle_key, NULL);
	mlx_hook(img.win_ptr, X_EVENT_CLOSE, 0, (void *)&close_window, 0);
//	mlx_key_hook(img.win_ptr, key_press, (void *) scene);
	mlx_loop(img.mlx_ptr);
	return (0);
}
