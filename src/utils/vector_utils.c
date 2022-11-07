#include "../../include/vector_utils.h"

double	vdot(t_vec3 vec, t_vec3 vec2)
{
	return (vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z);
}

t_vec3	vcross(t_vec3 vec, t_vec3 vec2)
{
	t_vec3	new;

	new.x = vec.y * vec2.z - vec.z * vec2.y;
	new.y = vec.z * vec2.x - vec.x * vec2.z;
	new.z = vec.x * vec2.y - vec.y * vec2.x;
	return (new);
}

t_vec3	vmin(t_vec3 vec1, t_vec3 vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.z;
	return (vec1);
}

t_vec3	vup(t_vec3 vec)
{
	if (vec.x == 0 && vec.y == 1 && vec.z == 0)
		return (vec3(0, 0, 1));
	if (vec.x == 0 && vec.y == -1 && vec.z == 0)
		return (vec3(0, 0, -1));
	return (vec3(0, 1, 0));
}
