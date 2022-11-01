#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "vector_utils.h"

# define _USE_MATH_DEFINES

t_canvas	canvas(int width, int height);
t_camera	set_camera(t_canvas *canvas, char **elements);
t_color3	set_ambient(char **ambient_values);
t_sphere	*new_sphere(t_point3 center, double radius);
t_object	*new_object(t_object_type type, void *element, t_color3 albedo);
t_sphere	*new_sphere(t_point3 center, double radius);
t_plain		*new_plain(t_point3 origin, t_vec3 dir_v, t_color3 color);
t_cylinder	*new_cylinder(t_point3 origin, t_vec3 dir_v, double dia, double height, t_color3 color);
t_light		*new_light_point(t_point3 light_origin, t_color3 light_color,
				double bright_ratio);

#endif
