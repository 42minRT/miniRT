#include "../../include/scene.h"
#include "../../include/object_utils.h"
#include "../../include/vector_utils.h"
#include "../../include/utils.h"

t_object	*init_world(t_rt_list *file)
{
	t_object	*world;
	t_rt_list	*file_idx;
	t_object 	*world_object;

	world = NULL;
	file_idx = file;
	world_object = NULL;
	while (file_idx != NULL)
	{
		world_object = get_new_object_in_list(file_idx);
		if (world_object != NULL)
			object_append(&world, world_object);
		file_idx = file_idx->next;
	}
	return (world);
}

t_scene	*init_scene(t_rt_list *file)
{
	t_scene		*scene;
	t_light		*lights;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->canvas = set_canvas(400, 200);
	scene->ambient = set_ambient(get_elements_by_type(file, A));
	scene->camera = set_camera(&scene->canvas, get_elements_by_type(file, C));
	scene->world = init_world(file);
	scene->light = new_light_point(point3(0, 25, 0), color3(1, 1, 1), 0.1);

	return (scene);
}
