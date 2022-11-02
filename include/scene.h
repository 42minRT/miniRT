#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "vector_utils.h"

# define _USE_MATH_DEFINES

t_scene		*init_scene(t_rt_list *file);
t_canvas	set_canvas(int width, int height);
t_camera	set_camera(t_canvas *canvas, char **elements);
t_color3	set_ambient(char **ambient_values);
t_sphere	*new_sphere(t_point3 center, double radius);
t_object	*new_object(t_object_type type, void *element, t_color3 albedo);
t_sphere	*new_sphere(t_point3 center, double radius);
t_plain		*new_plain(t_point3 origin, t_vec3 dir_v);
t_cylinder	*new_cylinder(t_point3 origin, t_vec3 dir_v, double dia, double height);
t_light		*new_light_point(t_point3 light_origin, t_color3 light_color,
				double bright_ratio);
t_object	*get_new_object_in_list(t_rt_list *rt_list);

#endif
