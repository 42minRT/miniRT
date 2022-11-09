#include "../../include/window.h"
#include "../../include/key_code.h"
#include "../../include/parse.h"
#include "../../include/scene.h"
#include "../../mlx/mlx.h"
#include "../../include/vector_utils.h"

static void	rotate_camera(t_scene *scene, t_vec3 axis)
{
	t_camera	cam;
	double		step;

	step = 0.042;
	cam = scene->camera;
	cam.w_dir = vunit(vplus(vmult(axis, step), cam.w_dir));
	set_cam_coordination(&cam.u_dir, &cam.v_dir, &cam.w_dir);
	cam.horizontal = vmult(cam.u_dir, cam.viewport_w);
	cam.vertical = vmult(cam.v_dir, cam.viewport_h);
	cam.left_bottom = vminus(
			vminus(vminus(cam.origin, vdivide(cam.horizontal, 2)),
				vdivide(cam.vertical, 2)), vmult(cam.w_dir, cam.focal_len));
	scene->camera = cam;
}

void	handle_key(int keycode, void *arg)
{
	t_scene	*scene;

	scene = (t_scene *)arg;
	if (keycode == KEY_ESC)
		close_window(EXIT_SUCCESS);
	if (keycode == KEY_Q)
	{
		(void) scene;
		// x 기준으로 ++
		rotate_camera(scene, vec3(1, 0, 0));
		draw_image(scene);
		mlx_put_image_to_window(scene->img.mlx_ptr, scene->img.win_ptr, scene->img.img, 0, 0);
	}
	if (keycode == KEY_W)
	{
		// y기준으로 ++ 
		rotate_camera(scene, vec3(0, 1, 0));
		draw_image(scene);
		mlx_put_image_to_window(scene->img.mlx_ptr, scene->img.win_ptr, scene->img.img, 0, 0);
	}
	if (keycode == KEY_E)
	{
		// z축 기준으로 ++ 
		rotate_camera(scene, vec3(0, 0, 1));
		draw_image(scene);
		mlx_put_image_to_window(scene->img.mlx_ptr, scene->img.win_ptr, scene->img.img, 0, 0);
	}
}

void	close_window(int status)
{
	exit(status);
}
