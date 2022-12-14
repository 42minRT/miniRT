#include "../../../include/trace.h"

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_ray	ray(t_point3 origin, t_vec3 dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = vunit(dir);
	return (ray);
}

t_point3	ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = vplus(ray->origin, vmult(ray->dir, t));
	return (at);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;
	t_vec3	temp;

	ray.origin = cam->origin;
	temp = vminus(vplus(vplus(cam->left_bottom, vmult(cam->horizontal, u)),
				vmult(cam->vertical, v)), cam->origin);
	ray.dir = vunit(temp);
	return (ray);
}

t_color3	ray_color(t_scene *scene)
{
	double			t;
	t_color3		white;
	t_color3		sky_blue;

	white = color3(1.0, 1.0, 1.0);
	sky_blue = color3(0.5, 0.7, 1.0);
	scene->rec = record_init();
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	t = 0.5 * (scene->ray.dir.y + 1.0);
	return (vplus(vmult(white, 1.0 - t), vmult(sky_blue, t)));
}
