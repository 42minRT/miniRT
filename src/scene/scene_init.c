#include "../../include/scene.h"
#include "../../include/object_utils.h"
#include "../../include/vector_utils.h"

t_scene	*scene_init(void)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	double		ka;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->canvas = canvas(400, 300);
	scene->camera = camera(&scene->canvas, point3(0, 0, 0));
	world = new_object(SP, new_sphere(point3(-2, 0, -5), 2), color3(0.5, 0, 0));
	object_append(&world, new_object(SP, new_sphere(point3(2, 0, -5), 2), color3(0, 0.5, 0)));
	object_append(&world, new_object(SP, new_sphere(point3(0, -1000, 0), 995), color3(1, 1, 1)));
	scene->world = world;
	lights = new_object(LIGHT_POINT, new_light_point(point3(0, 25, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	scene->light = lights;
	ka = 0.1;
	scene->ambient = vmult(color3(1, 1, 1), ka);
	return (scene);
}
