#include "../../include/window.h"
#include "../../include/key_code.h"
#include "../../include/parse.h"
#include "../../include/scene.h"
#include "../../mlx/mlx.h"
#include "../../include/vector_utils.h"

// set cam diretion to (origin cam dircetion + axis * step)
static void	plus_camera_direction(t_scene *scene, t_vec3 axis)
{
	t_camera		cam;
	const double	step = 0.042;

	cam = scene->camera;
	cam.w_dir = vunit(vplus(vmult(axis, step), cam.w_dir));
	set_cam_coordination(&cam.u_dir, &cam.v_dir, &cam.w_dir);
	cam.horizontal = vmult(cam.u_dir, cam.viewport_w);
	cam.vertical = vmult(cam.v_dir, cam.viewport_h);
	cam.left_bottom = vminus(
			vminus(vminus(cam.origin, vdivide(cam.horizontal, 2)),
				vdivide(cam.vertical, 2)),
			vmult(cam.w_dir, -1 * cam.focal_len));
	scene->camera = cam;
}

static void	plus_camera_coordination(t_scene *scene, t_keycode key)
{
	t_camera		cam;
	t_vec3			plus_vec;
	const double	step = 0.42;

	cam = scene->camera;
	if (key == KEY_RIGHT)
		plus_vec = vmult(cam.u_dir, step);
	else if (key == KEY_LEFT)
		plus_vec = vmult(cam.u_dir, step * (-1));
	else if (key == KEY_UP)
		plus_vec = vmult(cam.v_dir, step);
	else if (key == KEY_DOWN)
		plus_vec = vmult(cam.v_dir, step * (-1));
	else if (key == KEY_O)
		plus_vec = vmult(cam.w_dir, step * (-1));
	else
		plus_vec = vmult(cam.w_dir, step);
	cam.origin = vplus(cam.origin, plus_vec);
	cam.left_bottom = vplus(cam.left_bottom, plus_vec);
	scene->camera = cam;
}

void	handle_key(int keycode, void *arg)
{
	t_scene	*scene;

	scene = (t_scene *)arg;
	if (keycode == KEY_ESC)
		close_window(EXIT_SUCCESS);
	else if (keycode == KEY_W)
		plus_camera_direction(scene, scene->camera.v_dir);
	else if (keycode == KEY_A)
		plus_camera_direction(scene, vmult(scene->camera.u_dir, -1));
	else if (keycode == KEY_S)
		plus_camera_direction(scene, vmult(scene->camera.v_dir, -1));
	else if (keycode == KEY_D)
		plus_camera_direction(scene, scene->camera.u_dir);
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT || keycode == KEY_UP
		|| keycode == KEY_DOWN || keycode == KEY_O || keycode == KEY_I)
		plus_camera_coordination(scene, keycode);
	draw_image(scene);
	mlx_put_image_to_window(scene->img.mlx_ptr, scene->img.win_ptr,
		scene->img.img, 0, 0);
}

void	close_window(int status)
{
	exit(status);
}
