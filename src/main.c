#include "../include/parse.h"
#include "../include/print.h"
#include "../include/structures.h"
#include "../include/vector_utils.h"
#include "../include/object_utils.h"
#include "../include/color.h"
#include "../include/scene.h"
#include "../include/trace.h"
#include "../include/draw.h"
#include "../mlx/mlx.h"

int	main(int argc, char **argv)
{
    t_object    *world;
    t_scene     *scene;
	t_rt_list	*file;
	t_error		err;
	
	void	*mlx_ptr;
	void	*win_ptr; // 생성할 윈도우를 가리키는 포인터
	t_data		img;

	err = validate_file(argc, argv, &file);
	if (err != NO_ERROR)
		return (err);
	//file 을 이제 이케이케 잘 해야 한다

    scene = scene_init(); 	// scene/scene_init 에 있음
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, scene->canvas.width, scene->canvas.height, "Hellow World!");
	img.img = mlx_new_image(mlx_ptr, scene->canvas.width, scene->canvas.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_image(scene, &img); // 이미지를 그리자?
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr); // loop를 돌면서 event를 기다리고, 생성한 윈도우를 Rendering한다.
    return (0);
}
