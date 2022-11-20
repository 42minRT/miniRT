/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:53:51 by seongyle          #+#    #+#             */
/*   Updated: 2022/11/20 16:56:12 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/trace.h"

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	t_vec3	ret_vec;

	ret_vec = vminus(v, vmult(n, 2 * vdot(v, n)));
	return (ret_vec);
}

t_bool	in_shadow(t_object *world, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(world, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_p_light	phong_light;

	phong_light.light_dir = vminus(light->origin, scene->rec.p);
	phong_light.light_len = vlength(phong_light.light_dir);
	phong_light.light_ray = ray(vplus(scene->rec.p,
				vmult(scene->rec.normal, EPSILON)), phong_light.light_dir);
	if (in_shadow(scene->world, phong_light.light_ray, phong_light.light_len))
		return (color3(0, 0, 0));
	phong_light.light_dir = vunit(phong_light.light_dir);
	phong_light.kd = fmax(vdot(scene->rec.normal, phong_light.light_dir), 0.0);
	phong_light.diffuse = vmult(light->light_color, phong_light.kd);
	phong_light.view_dir = vunit(vmult(scene->ray.dir, -1));
	phong_light.reflect_dir = reflect(vmult(phong_light.light_dir, -1),
			scene->rec.normal);
	phong_light.ksn = 32;
	phong_light.ks = 0.5;
	phong_light.spec = pow(fmax(
				vdot(phong_light.view_dir, phong_light.reflect_dir), 0.0),
			phong_light.ksn);
	phong_light.specular = vmult(vmult(light->light_color, phong_light.ks),
			phong_light.spec);
	phong_light.brightness = light->bright_ratio * LUMEN;
	return (vmult(vplus(phong_light.diffuse, phong_light.specular),
			phong_light.brightness));
}

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_light		*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	light_color = vplus(light_color, point_light_get(scene, lights));
	light_color = vplus(light_color, scene->ambient);
	return (vmin(vmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}
