/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:23:40 by jimin             #+#    #+#             */
/*   Updated: 2022/11/11 13:24:42 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/scene.h"

t_object	*new_object(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	return (new);
}

t_sphere	*new_sphere(t_point3 center, double radius)
{
	t_sphere	*sp;

	sp = malloc(sizeof(t_sphere));
	if (!sp)
		return (NULL);
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

t_plane	*new_plane(t_point3 origin, t_vec3 dir_v)
{
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	if (pl == NULL)
		return (NULL);
	pl->origin = origin;
	pl->dir_v = dir_v;
	return (pl);
}

t_cylinder	*new_cylinder(
		t_point3 origin, t_vec3 dir_v, double dia, double height)
{
	t_cylinder	*cy;

	cy = malloc(sizeof(t_cylinder));
	if (cy == NULL)
		return (NULL);
	cy->origin = origin;
	cy->dir_v = dir_v;
	cy->diameter = dia;
	cy->height = height;
	return (cy);
}

t_light	*new_light(
		t_point3 light_origin, double bright_ratio, t_color3 light_color)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
