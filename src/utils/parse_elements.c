#include "../../include/structures.h"

char	**get_elements_by_type(t_rt_list *file, char *type)
{
	while (file->next)
	{
		if (ft_strncmp(type, file->type, ft_strlen(file->type)) == 0)
			return (file->elements);
		file = file->next;
	}
	return (NULL);
}