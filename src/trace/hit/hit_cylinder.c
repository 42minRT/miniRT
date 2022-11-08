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
	t_quadratic	equation;
	double		root;
	t_cylinder	*cy;

	cy = world->element;
	co = vminus(ray->origin, cy->origin);
	equation.a = pow(vdot(ray->dir, cy->dir_v), 2) - 1;
	equation.half_b = vdot(ray->dir, cy->dir_v) * vdot(co, cy->dir_v) - vdot(co, ray->dir);
	equation.c = pow(cy->diameter, 2) - vdot(co, co) + pow(vdot(co, cy->dir_v), 2);
	equation.discriminant = equation.half_b * equation.half_b - equation.a * equation.c;
	if (equation.discriminant < 0)
		return (FALSE);
	root = (-equation.half_b + sqrt(equation.discriminant)) / equation.a;
	if (root < rec->tmin || root > rec->tmax)
		return (FALSE);
	if (check_cylinder(world, ray, rec, root) == TRUE)
		return (TRUE);
	root = (-equation.half_b - sqrt(equation.discriminant)) / equation.a;
	if (check_cylinder(world, ray, rec, root) == TRUE)
		return (TRUE);
	return (FALSE);
}
