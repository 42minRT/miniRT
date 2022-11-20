/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:53:41 by seongyle          #+#    #+#             */
/*   Updated: 2022/11/20 16:56:05 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/structures.h"
#include "../../../include/vector_utils.h"
#include "../../../include/trace.h"

static void	set_rec(
	t_hit_record *rec, double root, t_ray *ray, t_object *world)
{
	t_sphere	*sp;

	sp = world->element;
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vunit(vminus(rec->p, sp->center));
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
}

t_bool	hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vec3		co;
	t_quadratic	equa;
	double		root;
	t_sphere	*sp;

	sp = world->element;
	co = vminus(ray->origin, sp->center);
	equa.a = vdot(ray->dir, ray->dir);
	equa.half_b = vdot(co, ray->dir);
	equa.c = vdot(co, co) - sp->radius2;
	equa.discriminant = equa.half_b * equa.half_b - equa.a * equa.c;
	if (equa.discriminant < 0)
		return (FALSE);
	root = (-equa.half_b - sqrt(equa.discriminant)) / equa.a;
	if (root < rec->tmin || root > rec->tmax)
	{
		root = (-equa.half_b + sqrt(equa.discriminant)) / equa.a;
		if (root < rec->tmin || root > rec->tmax)
			return (FALSE);
	}
	set_rec(rec, root, ray, world);
	return (TRUE);
}
