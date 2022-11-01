#include "../../include/scene.h"
#include "../../include/utils.h"

double	theta_to_radian(double theta)
{
	return (theta * M_PI / 180.0);
}

double	get_focal_len(double viewport_w, int fov)
{
	double	radian;
	double	a;
	double	b;

	radian = theta_to_radian(fov / 2.0);
	a = viewport_w / 2;
	b = tan(radian);
	return (a / b);
}

t_color3  set_ambient(char **ambient_values)
{
    return (vmult(parse_xyz_coordination(ambient_values[1]),
            ft_atod(ambient_values[0])));
}

t_camera	set_camera(t_canvas *canvas, char **elements)
{
	t_camera	cam;
	double		viewport_height;

	viewport_height = 2.0;
	cam.origin = parse_xyz_coordination(elements[0]);
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * canvas->aspect_ratio;
	cam.focal_len = get_focal_len(cam.viewport_w, ft_atoi(elements[2]));
	cam.horizontal = vec3(cam.viewport_w, 0, 0);
	cam.vertical = vec3(0, cam.viewport_h, 0);
	cam.left_bottom = vminus(vminus(vminus(cam.origin, vdivide(cam.horizontal, 2)),
				vdivide(cam.vertical, 2)), vec3(0, 0, cam.focal_len));
	return (cam);
}
