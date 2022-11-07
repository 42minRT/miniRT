#include "../../../include/structures.h"
#include "../../../include/vector_utils.h"
#include "../../../include/trace.h"

t_bool	check_cylinder(
		t_object *world, t_ray *ray, t_hit_record *rec, double root)
{
	t_cylinder	*cy;
	t_vec3		cp;
	t_vec3		cq;
	double		q_height;

	cy = world->element;
	rec->t = root;
	rec->p = ray_at(ray, root);
	cp = vminus(rec->p, cy->origin);
	cq = vmult(cy->dir_v, vdot(cp, cy->dir_v));
	q_height = vdot(cp, cy->dir_v);
	if (q_height < 0 || q_height > cy->height)
		return (FALSE);
	rec->normal = vunit(vminus(cp, cq));
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (TRUE);
}

t_bool	hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vec3		co;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;
	t_cylinder	*cy;

	cy = world->element;
	co = vminus(ray->origin, cy->origin);
	a = pow(vdot(ray->dir, cy->dir_v), 2) - 1;
	half_b = vdot(ray->dir, cy->dir_v) * vdot(co, cy->dir_v)
		- vdot(co, ray->dir);
	c = pow(cy->diameter, 2) - vdot(co, co) + pow(vdot(co, cy->dir_v), 2);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b + sqrtd) / a;
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
	if (check_cylinder(world, ray, rec, root) == TRUE)
		return (TRUE);
	root = (-half_b - sqrtd) / a;
	if (check_cylinder(world, ray, rec, root) == TRUE)
		return (TRUE);
	return (FALSE);
}
