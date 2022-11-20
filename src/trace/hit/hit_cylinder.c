/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:53:28 by seongyle          #+#    #+#             */
/*   Updated: 2022/11/20 16:56:01 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

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
	rec->tmax = root;
	rec->normal = vunit(vminus(cp, cq));
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (TRUE);
}

static t_is_return	is_hit(t_hit_record *rec, double root)
{
	if (root < rec->tmin || root > rec->tmax)
		return (NO);
	return (YES);
}

t_bool	hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vec3		co;
	t_quadratic	equa;
	double		p_root;
	double		m_root;
	t_cylinder	*cy;

	cy = world->element;
	co = vminus(ray->origin, cy->origin);
	equa.a = pow(vdot(ray->dir, cy->dir_v), 2) - 1;
	equa.half_b = vdot(ray->dir, cy->dir_v) * vdot(co, cy->dir_v)
		- vdot(co, ray->dir);
	equa.c = pow(cy->diameter, 2) - vdot(co, co) + pow(vdot(co, cy->dir_v), 2);
	equa.discriminant = equa.half_b * equa.half_b - equa.a * equa.c;
	if (equa.discriminant < 0)
		return (FALSE);
	p_root = (-equa.half_b + sqrt(equa.discriminant)) / equa.a;
	m_root = (-equa.half_b - sqrt(equa.discriminant)) / equa.a;
	if ((is_hit(rec, p_root) == YES && check_cylinder(world, ray, rec, p_root))
		|| (is_hit(rec, m_root) == YES
			&& check_cylinder(world, ray, rec, m_root)))
		return (TRUE);
	return (FALSE);
}
