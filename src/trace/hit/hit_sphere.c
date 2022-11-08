#include "../../../include/structures.h"
#include "../../../include/vector_utils.h"
#include "../../../include/trace.h"

t_bool	hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vec3		co;
	t_quadratic	equation;
	double		root;
	t_sphere	*sp;

	sp = world->element;
	co = vminus(ray->origin, sp->center);
	equation.a = vdot(ray->dir, ray->dir);
	equation.half_b = vdot(co, ray->dir);
	equation.c = vdot(co, co) - sp->radius2;
	equation.discriminant = equation.half_b * equation.half_b - equation.a * equation.c;
	if (equation.discriminant < 0)
		return (FALSE);
	root = (-equation.half_b - sqrt(equation.discriminant)) / equation.a;
	if (root < rec->tmin || root > rec->tmax)
	{
		root = (-equation.half_b + sqrt(equation.discriminant)) / equation.a;
		if (root < rec->tmin || root > rec->tmax)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vunit(vminus(rec->p, sp->center));
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (TRUE);
}
