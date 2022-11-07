#include "../../../include/structures.h"
#include "../../../include/vector_utils.h"
#include "../../../include/trace.h"

t_bool	hit_plane(t_object *world, t_ray *ray, t_hit_record *rec)
{
	double		a;
	double		b;
	double		t;
	t_plane		*pl;

	pl = world->element;
	a = vdot(ray->dir, pl->dir_v);
	if (a == 0)
		return (FALSE);
	b = vdot(pl->dir_v, vminus(pl->origin, ray->origin));
	t = b / a;
	if (t < rec->tmin || t > rec->tmax)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(ray, t);
	rec->normal = pl->dir_v;
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (TRUE);
}
