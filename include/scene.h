#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "vector_utils.h"

# define _USE_MATH_DEFINES

t_canvas	canvas(int width, int height);
t_camera camera(t_canvas *canvas, char **elements);
char **get_elements_by_type(t_rt_list *file, char *type);
t_sphere *new_sphere(t_point3 center, double radius);
t_object	*new_object(t_object_type type, void *element, t_color3 albedo);
t_light		*new_light_point(t_point3 light_origin, t_color3 light_color,
			double bright_ratio);
t_scene		*scene_init(t_rt_list *file);

#endif
