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

t_plain	*new_plain(t_point3 origin, t_vec3 dir_v)
{
	t_plain	*pl;

	pl = malloc(sizeof(t_plain));
	if (pl == NULL)
		return (NULL);
	pl->origin = origin;
	pl->dir_v = dir_v;
	return (pl);
}

t_cylinder	*new_cylinder(t_point3 origin, t_vec3 dir_v, double dia, double height)
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

t_light	*new_light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
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

